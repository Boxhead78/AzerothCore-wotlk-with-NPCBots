-- Make sure no alliance bots spawn in horde starting zones and no horde bots spawn in alliance starting zones
-- Durotar
UPDATE creature_template_npcbot_wander_nodes
SET flags = 5
WHERE flags = 1
AND zoneid = 14;

-- Barrens
UPDATE creature_template_npcbot_wander_nodes
SET flags = 5
WHERE flags = 1
AND zoneid = 17;

-- Mulgore
UPDATE creature_template_npcbot_wander_nodes
SET flags = 5
WHERE flags = 1
AND zoneid = 215;

-- Tirisfal
UPDATE creature_template_npcbot_wander_nodes
SET flags = 5
WHERE flags = 1
AND zoneid = 85;

-- Eversong Woods
UPDATE creature_template_npcbot_wander_nodes
SET flags = 5
WHERE flags = 1
AND zoneid = 3430;

-- Ghostlands
UPDATE creature_template_npcbot_wander_nodes
SET flags = 5
WHERE flags = 1
AND zoneid = 3433;

-- Teldrassil
UPDATE creature_template_npcbot_wander_nodes
SET flags = 3
WHERE flags = 1
AND zoneid = 141;

-- Azuremyst
UPDATE creature_template_npcbot_wander_nodes
SET flags = 3
WHERE flags = 1
AND zoneid = 3524;

-- Bloodmyst
UPDATE creature_template_npcbot_wander_nodes
SET flags = 3
WHERE flags = 1
AND zoneid = 3525;

-- Duskwood
UPDATE creature_template_npcbot_wander_nodes
SET flags = 3
WHERE flags = 1
AND zoneid = 10;

-- Elwynn Forest
UPDATE creature_template_npcbot_wander_nodes
SET flags = 3
WHERE flags = 1
AND zoneid = 12;

-- Westfall
UPDATE creature_template_npcbot_wander_nodes
SET flags = 3
WHERE flags = 1
AND zoneid = 40;

-- Dun Morogh
UPDATE creature_template_npcbot_wander_nodes
SET flags = 3
WHERE flags = 1
AND zoneid = 1;

-- Loch Modan
UPDATE creature_template_npcbot_wander_nodes
SET flags = 3
WHERE flags = 1
AND zoneid = 38;