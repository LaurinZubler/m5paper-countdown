#include <gtest/gtest.h>
#include <BatteryHelper.h>

TEST(BatteryHelper, getBatteryPercentageFromVoltage_100) {
    int unsigned voltage = 4350; 
    int batteryPercentage = BatteryHelper::getBatteryPercentageFromVoltage(voltage);
    ASSERT_EQ(batteryPercentage, 100);
}

TEST(BatteryHelper, getBatteryPercentageFromVoltage_0) {
    int unsigned voltage = 3000; 
    int batteryPercentage = BatteryHelper::getBatteryPercentageFromVoltage(voltage);
    ASSERT_EQ(batteryPercentage, 0);
}

TEST(BatteryHelper, getBatteryPercentageFromVoltage_above_max) {
    int unsigned voltage = 5000; 
    int batteryPercentage = BatteryHelper::getBatteryPercentageFromVoltage(voltage);
    ASSERT_EQ(batteryPercentage, 100);
}

TEST(BatteryHelper, getBatteryPercentageFromVoltage_below_min) {
    int unsigned voltage = 2000; 
    int batteryPercentage = BatteryHelper::getBatteryPercentageFromVoltage(voltage);
    ASSERT_EQ(batteryPercentage, 0);
}

TEST(BatteryHelper, getBatteryPercentageFromVoltage_half) {
    int unsigned voltage = 3675; 
    int batteryPercentage = BatteryHelper::getBatteryPercentageFromVoltage(voltage);
    ASSERT_EQ(batteryPercentage, 50);
}
