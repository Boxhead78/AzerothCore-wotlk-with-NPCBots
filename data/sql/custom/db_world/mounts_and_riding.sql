-- Re-enable Summon Felsteed (Warlock)
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (3631, 4487, 4488, 4489, 4490);

-- Set mails to new riding skill levels
UPDATE `mail_level_reward` SET `level` = 30 WHERE `level` = 20;
UPDATE `mail_level_reward` SET `level` = 60 WHERE `level` = 40;

-- Update riding quests level
UPDATE `quest_template` SET `QuestLevel` = 30, `MinLevel` = 30 WHERE `ID` IN (14079, 14080, 14081, 14082, 14083, 14084, 14085, 14086, 14087, 14088, 14089);

-- Move letter about cold weather flying to level 71 instead of 70, as in Wotlk classic
UPDATE `mail_level_reward` SET `level` = 71 WHERE `mailTemplateId` IN (285, 284);

-- Riding Skills
UPDATE npc_trainer SET MoneyCost=800000, ReqLevel=30 WHERE SpellID=33388;
UPDATE npc_trainer SET MoneyCost=10000000 WHERE SpellID=33391;
UPDATE npc_trainer SET MoneyCost=50000000 WHERE SpellID=34090;
UPDATE npc_trainer SET MoneyCost=100000000 WHERE SpellID=34091;
DELETE FROM npc_trainer WHERE SpellID=23214;
DELETE FROM npc_trainer WHERE SpellID=34767;
DELETE FROM npc_trainer WHERE SpellID=23161;
DELETE FROM npc_trainer WHERE SpellID=13819; # Delete Summon Warhorse from trainer - it is a free reward from a quest instead
DELETE FROM npc_trainer WHERE SpellID=13820; # Delete Summon Warhorse from more trainers