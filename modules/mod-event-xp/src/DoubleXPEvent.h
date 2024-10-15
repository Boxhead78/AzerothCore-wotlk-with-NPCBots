#ifndef AZEROTHCORE_DOUBLEXPEVENT_H
#define AZEROTHCORE_DOUBLEXPEVENT_H

#include "Configuration/Config.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"
#include <time.h>

class DoubleXPEvent
{
public:
    static DoubleXPEvent* instance();
    float GetXPEventExperienceRate(Player* player) const;
    bool IsXPEventActive() const;
private:
    std::vector<HolidayIds> holidaysToCheck = {
        HOLIDAY_FEAST_OF_WINTER_VEIL,
        HOLIDAY_NOBLEGARDEN,
        HOLIDAY_CHILDRENS_WEEK,
        HOLIDAY_HARVEST_FESTIVAL,
        HOLIDAY_HALLOWS_END,
        HOLIDAY_LUNAR_FESTIVAL,
        HOLIDAY_FIRE_FESTIVAL,
        HOLIDAY_BREWFEST,
        HOLIDAY_PIRATES_DAY,
        HOLIDAY_PILGRIMS_BOUNTY,
        HOLIDAY_DAY_OF_DEAD,
        HOLIDAY_LOVE_IS_IN_THE_AIR
    };

    bool CheckHolidays() const;
};

#define sXPEvent DoubleXPEvent::instance()

#endif // AZEROTHCORE_DOUBLEXPEVENT_H
