#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "CountdownTimer.h"

// Test for CountdownTimer::getDaysRemaining
TEST(CountdownTimerTests, getDaysRemaining) {
    // Mock today's date as Dec 1, 2024
    tm currentTime = {0};
    currentTime.tm_year = 2024 - 1900;
    currentTime.tm_mon = 11; // December (0-based)
    currentTime.tm_mday = 1;

    // Set system time (mocked for test purposes)
    time_t mockTime = mktime(&currentTime);
    time_t realTime = time(nullptr); // Save real system time
    time(nullptr) = [&mockTime]() { return mockTime; };

    // Create a countdown to Dec 25, 2024
    CountdownTimer timer(2024, 12, 25);
    int daysRemaining = timer.getDaysRemaining();

    ASSERT_EQ(daysRemaining, 24); // Expected: 24 days

    // Restore real system time
    time(nullptr) = [&realTime]() { return realTime; };
}
