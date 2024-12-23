#include <gtest/gtest.h>
#include <DateUtils.h>

TEST(DateUtils, getDaysBetween) {
    tm date1 = {0};
    tm date2 = {0};

    // 2024-01-01
    date1.tm_year = 2024 - 1900;
    date1.tm_mon = 0;
    date1.tm_mday = 1;

    // 2024-01-10
    date2.tm_year = 2024 - 1900;
    date2.tm_mon = 0;
    date2.tm_mday = 10;

    int days = DateUtils::getDaysBetween(date1, date2);
    ASSERT_EQ(days, 9);
}

TEST(DateUtils, getDaysBetween_withTime) {
    tm date1 = {0};
    tm date2 = {0};

    // 2024-01-01 12:15
    date1.tm_year = 2024 - 1900;
    date1.tm_mon = 0;
    date1.tm_mday = 1;
    date1.tm_hour = 11;
    date1.tm_min = 14;

    // 2024-01-10 00:00
    date2.tm_year = 2024 - 1900;
    date2.tm_mon = 0;
    date2.tm_mday = 10;

    int days = DateUtils::getDaysBetween(date1, date2);
    ASSERT_EQ(days, 9);
}

