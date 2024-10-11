#include "map.h"
#include "Log.h"
#include "Config.h"
#include "ScriptMgr.h"
#include "Unit.h"

bool RaidAdjustmentEnabled;
float RaidAdjustmentClassicMeleeDamageMult;
float RaidAdjustmentClassicSpellDamageMult;
float RaidAdjustmentTBCMeleeDamageMult;
float RaidAdjustmentTBCSpellDamageMult;
float RaidAdjustmentWotLKMeleeDamageMult;
float RaidAdjustmentWotLKSpellDamageMult;

class RaidAdjustmentConfig : public WorldScript
{
public:
    RaidAdjustmentConfig() : WorldScript("RaidAdjustmentConfig") {}

    void OnBeforeConfigLoad(bool reload) override
    {
        if (!reload) {
            // Load Configuration Settings
            SetInitialWorldSettings();
        }
    }

    // Load Configuration Settings
    void SetInitialWorldSettings()
    {
        //Enable Disable
        RaidAdjustmentEnabled = sConfigMgr->GetOption<bool>("RaidAdjustment.Enable", 1);

		//Balancing
        RaidAdjustmentClassicMeleeDamageMult = sConfigMgr->GetOption<float>("RaidAdjustment.Classic.DamageTaken.Melee", 1.0);
        RaidAdjustmentClassicSpellDamageMult = sConfigMgr->GetOption<float>("RaidAdjustment.Classic.DamageTaken.Spell", 1.0);
        RaidAdjustmentTBCMeleeDamageMult = sConfigMgr->GetOption<float>("RaidAdjustment.TBC.DamageTaken.Melee", 1.0);
        RaidAdjustmentTBCSpellDamageMult = sConfigMgr->GetOption<float>("RaidAdjustment.TBC.DamageTaken.Spell", 1.0);
        RaidAdjustmentWotLKMeleeDamageMult = sConfigMgr->GetOption<float>("RaidAdjustment.WotLK.DamageTaken.Melee", 1.0);
        RaidAdjustmentWotLKSpellDamageMult = sConfigMgr->GetOption<float>("RaidAdjustment.WotLK.DamageTaken.Spell", 1.0);
    }
};

class raidadjustment_player_unit_script : public UnitScript {
public:

    raidadjustment_player_unit_script() : UnitScript("raidadjustment_player_unit_script") { }

    void ModifySpellDamageTaken(Unit* target, Unit* attacker, int32& damage, SpellInfo const* spellInfo) override
    {
        if (!RaidAdjustmentEnabled || !target)
            return;

        if (!target->GetMap()->IsRaid())
        {
            return;
        }

        if (target->GetTypeId() != TYPEID_PLAYER && !target->IsNPCBotOrPet())
        {
            return;
        }

        if (sMapStore.LookupEntry(target->GetMapId())->Expansion() == CONTENT_1_60)
            damage *= RaidAdjustmentClassicSpellDamageMult;

        if (sMapStore.LookupEntry(target->GetMapId())->Expansion() == CONTENT_61_70)
            damage *= RaidAdjustmentTBCSpellDamageMult;

        if (sMapStore.LookupEntry(target->GetMapId())->Expansion() == CONTENT_71_80)
            damage *= RaidAdjustmentWotLKSpellDamageMult;
    }
    void ModifyMeleeDamage(Unit* target, Unit* attacker, uint32& damage) override
    {
        if (!RaidAdjustmentEnabled || !target)
            return;

        if (!target->GetMap()->IsRaid())
        {
            return;
        }

        if (target->GetTypeId() != TYPEID_PLAYER && !target->IsNPCBotOrPet())
        {
            return;
        }

        if (sMapStore.LookupEntry(target->GetMapId())->Expansion() == CONTENT_1_60)
            damage *= RaidAdjustmentClassicMeleeDamageMult;

        if (sMapStore.LookupEntry(target->GetMapId())->Expansion() == CONTENT_61_70)
            damage *= RaidAdjustmentTBCMeleeDamageMult;

        if (sMapStore.LookupEntry(target->GetMapId())->Expansion() == CONTENT_71_80)
            damage *= RaidAdjustmentWotLKMeleeDamageMult;
    }
};

void AddRaidAdjustmentScripts()
{
    new RaidAdjustmentConfig();
    new raidadjustment_player_unit_script();
}
