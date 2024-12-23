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

TEST(DateUtils, getSecondsUntilMidnight_24h) {
    tm date = {0};

    int expected = 60 * 60 * 24;
    int seconds = DateUtils::getSecondsUntilMidnight(date);

    ASSERT_EQ(seconds, expected);
}

TEST(DateUtils, getSecondsUntilMidnight_1h) {
    tm date = {0};
    date.tm_hour = 23;

    int expected = 60 * 60;
    int seconds = DateUtils::getSecondsUntilMidnight(date);

    ASSERT_EQ(seconds, expected);
}

TEST(DateUtils, getSecondsUntilMidnight_1min) {
    tm date = {0};
    date.tm_hour = 23;
    date.tm_min = 59;

    int expected = 60;
    int seconds = DateUtils::getSecondsUntilMidnight(date);

    ASSERT_EQ(seconds, expected);
}

TEST(DateUtils, getSecondsUntilMidnight_1s) {
    tm date = {0};
    date.tm_hour = 23;
    date.tm_min = 59;
    date.tm_sec = 59;

    int expected = 1;
    int seconds = DateUtils::getSecondsUntilMidnight(date);

    ASSERT_EQ(seconds, expected);
}

TEST(DateUtils, getSecondsUntilMidnight_0s) {
    tm date = {0};
    date.tm_hour = 23;
    date.tm_min = 59;
    date.tm_sec = 60;

    int expected = 0;
    int seconds = DateUtils::getSecondsUntilMidnight(date);

    ASSERT_EQ(seconds, expected);
}

