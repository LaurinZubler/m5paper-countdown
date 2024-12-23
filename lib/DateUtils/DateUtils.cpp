#include "DateUtils.h"

int DateUtils::getDaysBetween(const tm& date1, const tm& date2) {
    const time_t time1 = mktime(const_cast<tm*>(&date1));
    const time_t time2 = mktime(const_cast<tm*>(&date2));
    const double diff = difftime(time2, time1);
    const int days = static_cast<int>(diff / (60 * 60 * 24));
    return days;
}

int DateUtils::getSecondsUntilMidnight() {
    tm* now = getCurrentDateTime();

    return (23 - now->tm_hour) * 3600 +
           (59 - now->tm_min) * 60 +
           (60 - now->tm_sec);
}

tm* DateUtils::getCurrentDateTime() {
    time_t now = time(nullptr);
    return localtime(&now);
}