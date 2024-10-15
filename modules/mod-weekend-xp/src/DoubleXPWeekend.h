#ifndef AZEROTHCORE_DOUBLEXPWEEKEND_H
#define AZEROTHCORE_DOUBLEXPWEEKEND_H

#include "Configuration/Config.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"
#include <time.h>

enum WeekendXP
{
    SETTING_WEEKEND_XP_RATE = 0,

    WD_FRIDAY = 5,
    WD_SATURDAY = 6,
    WD_SUNDAY = 0
};

class DoubleXpWeekend
{
public:
    static DoubleXpWeekend* instance();
    float GetXPWeekendExperienceRate(Player* player) const;
    bool IsXPWeekendEventActive() const;
};

#define sXPWeekend DoubleXpWeekend::instance()

#endif // AZEROTHCORE_DOUBLEXPWEEKEND_H
