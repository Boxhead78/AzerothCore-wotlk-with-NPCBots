#include "Configuration/Config.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"
#include "time.h"
#include "DoubleXPWeekend.h"

DoubleXpWeekend* DoubleXpWeekend::instance()
{
    static DoubleXpWeekend instance;
    return &instance;
}

float DoubleXpWeekend::GetXPWeekendExperienceRate(Player* player) const
{
    float rate = sConfigMgr->GetOption<float>("XPWeekend.xpAmount", 1);

    // Prevent returning 0% rate.
    return rate ? rate : 1;
}

bool DoubleXpWeekend::IsXPWeekendEventActive() const
{
    if (sConfigMgr->GetOption<bool>("XPWeekend.AlwaysEnabled", false))
        return true;

    if (!sConfigMgr->GetOption<bool>("XPWeekend.Enabled", false))
        return false;

    time_t t = time(nullptr);
    tm* now = localtime(&t);

    return now->tm_wday == WD_FRIDAY || now->tm_wday == WD_SATURDAY || now->tm_wday == WD_SUNDAY;
}

class DoubleXpWeekendScripts : public PlayerScript
{
public:
    DoubleXpWeekendScripts() : PlayerScript("DoubleXpWeekendScripts") { }

    void OnLogin(Player* player) override
    {
        if (sConfigMgr->GetOption<bool>("XPWeekend.Announce", false))
        {
            if (sXPWeekend->IsXPWeekendEventActive())
            {
                uint32 loc = player->GetSession()->GetSessionDbLocaleIndex();
                if (loc == 3)
                    ChatHandler(player->GetSession()).PSendSysMessage("Es ist Wochenende! Deine Erfahrung wurde auf {} gesetzt.", sXPWeekend->GetXPWeekendExperienceRate(player));
                else
                    ChatHandler(player->GetSession()).PSendSysMessage("It's the weekend! Your XP rate has been set to {}.", sXPWeekend->GetXPWeekendExperienceRate(player));
            }
            else
            {
                uint32 loc = player->GetSession()->GetSessionDbLocaleIndex();
                if (loc == 3)
                    ChatHandler(player->GetSession()).PSendSysMessage("Dieser Server nutzt das |cff4CFF00Double XP Weekend |rModul.");
                else
                    ChatHandler(player->GetSession()).PSendSysMessage("This server is running the |cff4CFF00Double XP Weekend |rmodule.");
            }
        }
    }


    void OnGiveXP(Player* player, uint32& amount, Unit* victim, uint8 /*xpSource*/) override
    {
        if (!sXPWeekend->IsXPWeekendEventActive())
        {
            return;
        }

        if (sConfigMgr->GetOption<bool>("XPWeekend.QuestOnly", false) && victim && victim->GetTypeId() == TYPEID_UNIT && !victim->ToCreature()->hasLootRecipient())
        {
            return;
        }

        if (player->GetLevel() >= sConfigMgr->GetOption<uint32>("XPWeekend.MaxLevel", 80))
        {
            return;
        }

        amount *= sXPWeekend->GetXPWeekendExperienceRate(player);
    }
};

void AddScripts_WeekendXP()
{
    new DoubleXpWeekendScripts();
}
