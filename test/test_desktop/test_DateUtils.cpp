#include <gtest/gtest.h>
#include <DateUtils.h>

TEST(DateUtils, getDaysBetween) {
    tm date1 = {0, 0, 0, 1, 0, 2024 - 1900};  // 2024-01-01
    tm date2 = {0, 0, 0, 10, 0, 2024 - 1900}; // 2024-01-10

    int days = DateUtils::getDaysBetween(date1, date2);
    ASSERT_EQ(days, 9);
}

TEST(DateUtils, getDaysBetween_withTime_morning) {
    tm date1 = {0, 15, 10, 1, 0, 2024 - 1900}; // 2024-01-01 10:15
    tm date2 = {0, 0, 0, 10, 0, 2024 - 1900};  // 2024-01-10

    int days = DateUtils::getDaysBetween(date1, date2);
    ASSERT_EQ(days, 9);
}

TEST(DateUtils, getDaysBetween_withTime_afternoon) {
    tm date1 = {0, 15, 14, 1, 0, 2024 - 1900}; // 2024-01-01 14:15
    tm date2 = {0, 0, 0, 10, 0, 2024 - 1900};  // 2024-01-10

    int days = DateUtils::getDaysBetween(date1, date2);
    ASSERT_EQ(days, 9);
}

TEST(DateUtils, getDaysBetween_sameDay) {
    tm date1 = {0, 0, 0, 1, 0, 2024 - 1900};  // 2024-01-01

    int days = DateUtils::getDaysBetween(date1, date1);
    ASSERT_EQ(days, 0);
}

TEST(DateUtils, getDaysBetween_wrong_order) {
    tm date1 = {0, 0, 0, 1, 0, 2024 - 1900};  // 2024-01-01
    tm date2 = {0, 0, 0, 10, 0, 2024 - 1900}; // 2024-01-10

    // 2024-01-01
    date1.tm_year = 2024 - 1900;
    date1.tm_mon = 0;
    date1.tm_mday = 1;

    // 2024-01-10 00:00
    date2.tm_year = 2024 - 1900;
    date2.tm_mon = 0;
    date2.tm_mday = 10;

    int days = DateUtils::getDaysBetween(date2, date1);
    ASSERT_EQ(days, -9);
}
