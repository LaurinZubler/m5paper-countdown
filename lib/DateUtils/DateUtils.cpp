#include "DateUtils.h"

int DateUtils::getDaysBetween(const tm& date1, const tm& date2) {
    const tm date1AtStartOfDay = {0, 0, 0, date1.tm_mday, date1.tm_mon, date1.tm_year};
    const tm date2AtStartOfDay = {0, 0, 0, date2.tm_mday, date2.tm_mon, date2.tm_year};

    const time_t time1 = mktime(const_cast<tm*>(&date1AtStartOfDay));
    const time_t time2 = mktime(const_cast<tm*>(&date2AtStartOfDay));
    const double diff = difftime(time2, time1);
    const int days = static_cast<int>(diff / (60 * 60 * 24));
    return days;
}

int DateUtils::getSecondsUntilMidnight(const tm& date) {
    return (23 - date.tm_hour) * 3600 +
           (59 - date.tm_min) * 60 +
           (60 - date.tm_sec);
}
