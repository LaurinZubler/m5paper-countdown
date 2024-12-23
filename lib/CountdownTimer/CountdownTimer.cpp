#include "CountdownTimer.h"
#include "DateUtils.h"

CountdownTimer::CountdownTimer(const int year, const int month, const int day) {
    targetDate = {};
    targetDate.tm_year = year - 1900; // tm_year is years since 1900
    targetDate.tm_mon = month - 1;    // tm_mon is 0-based
    targetDate.tm_mday = day;
}

int CountdownTimer::getDaysRemaining(const tm& now) const {
    return DateUtils::getDaysBetween(now, targetDate);
}
