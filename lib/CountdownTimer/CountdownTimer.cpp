#include "CountdownTimer.h"
#include "DateUtils.h"
#include <sstream>

CountdownTimer::CountdownTimer(int year, int month, int day) {
    targetDate = {};
    targetDate.tm_year = year - 1900; // tm_year is years since 1900
    targetDate.tm_mon = month - 1;    // tm_mon is 0-based
    targetDate.tm_mday = day;
}

int CountdownTimer::getDaysRemaining() const {
    const time_t now = time(nullptr);
    const tm* today = localtime(&now);
    return DateUtils::getDaysBetween(*today, targetDate);
}
