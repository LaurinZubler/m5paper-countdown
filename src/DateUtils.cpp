#include "DateUtils.h"

int DateUtils::getDaysBetween(const tm& date1, const tm& date2) {
    time_t t1 = mktime(const_cast<tm*>(&date1));
    time_t t2 = mktime(const_cast<tm*>(&date2));
    return static_cast<int>(difftime(t2, t1) / (60 * 60 * 24));
}

int DateUtils::getSecondsUntilMidnight() {
    tm* now = DateUtils::getCurrentDateTime();

    return (23 - now->tm_hour) * 3600 +
           (59 - now->tm_min) * 60 +
           (60 - now->tm_sec);
}

tm* DateUtils::getCurrentDateTime() {
    time_t now = time(nullptr);
    return localtime(&now);
}
