#include <gtest/gtest.h>
#include "CountdownTimer.h"

TEST(CountdownTimer, getDaysRemaining) {
    CountdownTimer timer(2024, 12, 24);      // 2024-12-24
    tm now = {0, 0, 0, 1, 11, 2024 - 1900};  // 2024-12-01

    int daysRemaining = timer.getDaysRemaining(now);
    int expected = 23;

    ASSERT_EQ(daysRemaining, expected);
}

TEST(CountdownTimer, getDaysRemaining_sameDay) {
    CountdownTimer timer(2024, 12, 24);       // 2024-12-24
    tm now = {0, 0, 0, 24, 11, 2024 - 1900};  // 2024-12-01

    int daysRemaining = timer.getDaysRemaining(now);
    int expected = 0;

    ASSERT_EQ(daysRemaining, expected);
}
