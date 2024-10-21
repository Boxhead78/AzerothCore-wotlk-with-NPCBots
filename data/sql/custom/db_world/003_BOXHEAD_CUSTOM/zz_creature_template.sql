DELETE FROM `creature_template` WHERE `entry`=50000;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `speed_swim`, `speed_flight`, `detection_range`, `scale`, `rank`, `dmgschool`, `DamageModifier`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (50000, 0, 0, 0, 0, 0, 'Disidra Stormglory', 'Individual Progression', 'Speak', 0, 83, 83, 2, 35, 1, 1, 1.14286, 1, 1, 18, 1.15, 2, 0, 32.55, 2000, 2000, 1, 1, 8, 33280, 2048, 0, 0, 0, 0, 0, 0, 7, 0, 0, 3296, 0, 0, 0, 1, 714, 'SmartAI', 0, 1, 39, 1, 1, 1, 0, 0, 0, 667631227, 0, 2, 'npc_ipp_individual_progression_setter', 12340);


UPDATE `creature_template`
SET `HealthModifier` = 35
WHERE entry = 27656;

UPDATE `creature_template`
SET `HealthModifier` = 35
WHERE entry = 31619;

UPDATE `creature_template`
SET `HealthModifier` = 50
WHERE entry = 31561;

UPDATE `creature_template`
SET `HealthModifier` = 5000
WHERE entry = 30161;

UPDATE `creature_template`
SET `HealthModifier` = 160
WHERE entry = 33113;

UPDATE `creature_template`
SET `speed_walk` = 3.5, `speed_run` = 3, `HealthModifier` = 360
WHERE entry = 33060;

UPDATE `creature_template`
SET `speed_walk` = 6, `speed_run` = 5, `HealthModifier` = 160
WHERE entry = 33062;

UPDATE `creature_template`
SET `speed_walk` = 5, `speed_run` = 3.75, `HealthModifier` = 200
WHERE entry = 33109;

UPDATE `creature_template`
SET `HealthModifier` = 430
WHERE entry = 37846;

UPDATE `creature_template`
SET `HealthModifier` = 500
WHERE entry = 37955;

UPDATE `creature_template`
SET `HealthModifier` = 430
WHERE entry = 38004;

UPDATE `creature_template`
SET `HealthModifier` = 2100
WHERE entry = 38434;

UPDATE `creature_template`
SET `HealthModifier` = 650
WHERE entry = 33435;

UPDATE `creature_template`
SET `HealthModifier` = 2500
WHERE entry = 33436;

UPDATE `creature_template`
SET `HealthModifier` = 350
WHERE entry = 36678;

UPDATE `creature_template`
SET `HealthModifier` = 1000
WHERE entry = 38216;

UPDATE `creature_template`
SET `HealthModifier` = 1500
WHERE entry = 38431;

UPDATE `creature_template`
SET `HealthModifier` = 490
WHERE entry = 38585;

UPDATE `creature_template`
SET `HealthModifier` = 1800
WHERE entry = 38586;

UPDATE `creature_template`
SET `HealthModifier` = 0.75
WHERE entry = 17954;