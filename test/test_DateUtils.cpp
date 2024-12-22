#include <gtest/gtest.h>
#include "DateUtils.h"

// Test for getDaysBetween
TEST(DateUtilsTests, GetDaysBetween) {
    tm date1 = {0};
    tm date2 = {0};

    // Set date1 to Jan 1, 2024
    date1.tm_year = 2024 - 1900;
    date1.tm_mon = 0;
    date1.tm_mday = 1;

    // Set date2 to Jan 10, 2024
    date2.tm_year = 2024 - 1900;
    date2.tm_mon = 0;
    date2.tm_mday = 10;

    int days = DateUtils::getDaysBetween(date1, date2);
    ASSERT_EQ(days, 9); // Expected: 9 days
}

// Test for getSecondsUntilMidnight
TEST(DateUtilsTests, GetSecondsUntilMidnight) {
    // Mock current time as 23:00:00
    tm currentTime = {0};
    currentTime.tm_hour = 23;
    currentTime.tm_min = 0;
    currentTime.tm_sec = 0;

    // Set system time (mocked for test purposes)
    time_t mockTime = mktime(&currentTime);
    time_t realTime = time(nullptr); // Save real system time
    time(nullptr) = [&mockTime]() { return mockTime; };

    int seconds = DateUtils::getSecondsUntilMidnight();
    ASSERT_EQ(seconds, 3600); // Expected: 1 hour = 3600 seconds

    // Restore real system time
    time(nullptr) = [&realTime]() { return realTime; };
}
