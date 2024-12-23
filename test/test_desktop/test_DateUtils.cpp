#include <gtest/gtest.h>
#include <DateUtils.h>

// Test for getDaysBetween
TEST(DateUtils, getDaysBetween) {
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
    ASSERT_EQ(days, 9);
}

