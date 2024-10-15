#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"
#include "DoubleXPEvent.h"

DoubleXPEvent* DoubleXPEvent::instance()
{
    static DoubleXPEvent instance;
    return &instance;
}

float DoubleXPEvent::GetXPEventExperienceRate(Player* player) const
{
    float rate = sConfigMgr->GetOption<float>("XPEvent.xpAmount", 1);

    // Prevent returning 0% rate.
    return rate ? rate : 1;
}

bool DoubleXPEvent::IsXPEventActive() const
{
    if (!sConfigMgr->GetOption<bool>("XPEvent.Enabled", false))
        return false;

    return CheckHolidays();
}

bool DoubleXPEvent::CheckHolidays() const
{
    for (HolidayIds holiday : holidaysToCheck)
        if (IsHolidayActive(holiday))
            return true;

    return false;
}

class DoubleXPEventScripts : public PlayerScript
{
public:
    DoubleXPEventScripts() : PlayerScript("DoubleXPEventScripts") { }

    void OnLogin(Player* player) override
    {
        if (sConfigMgr->GetOption<bool>("XPEvent.Announce", false))
        {
            if (sXPEvent->IsXPEventActive())
            {
                uint32 loc = player->GetSession()->GetSessionDbLocaleIndex();
                if (loc == 3)
                    ChatHandler(player->GetSession()).PSendSysMessage("Ein Event findet statt! Deine Erfahrung wurde auf {} gesetzt.", sXPEvent->GetXPEventExperienceRate(player));
                else
                    ChatHandler(player->GetSession()).PSendSysMessage("It's time for an event! Your XP rate has been set to {}.", sXPEvent->GetXPEventExperienceRate(player));
            }
            else
            {
                uint32 loc = player->GetSession()->GetSessionDbLocaleIndex();
                if (loc == 3)
                    ChatHandler(player->GetSession()).PSendSysMessage("Dieser Server nutzt das |cff4CFF00Double XP Event |rModul.");
                else
                    ChatHandler(player->GetSession()).PSendSysMessage("This server is running the |cff4CFF00Double XP Event |rmodule.");
            }
        }
    }


    void OnGiveXP(Player* player, uint32& amount, Unit* victim, uint8 /*xpSource*/) override
    {
        if (!sXPEvent->IsXPEventActive())
        {
            return;
        }

        if (sConfigMgr->GetOption<bool>("XPEvent.QuestOnly", false) && victim && victim->GetTypeId() == TYPEID_UNIT && !victim->ToCreature()->hasLootRecipient())
        {
            return;
        }

        if (player->GetLevel() >= sConfigMgr->GetOption<uint32>("XPEvent.MaxLevel", 80))
        {
            return;
        }

        amount *= sXPEvent->GetXPEventExperienceRate(player);
    }
};

void AddScripts_EventXP()
{
    new DoubleXPEventScripts();
}
