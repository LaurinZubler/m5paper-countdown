#include "BatteryHelper.h"

const int MAX_VOLTAGE = 4350;
const int MIN_VOLTAGE = 3000;

int BatteryHelper::getBatteryPercentageFromVoltage(const unsigned int voltage) {
    if (voltage > MAX_VOLTAGE) return 100;
    if (voltage < MIN_VOLTAGE) return 0;

    const float battery = static_cast<float>(voltage - MIN_VOLTAGE) / static_cast<float>(MAX_VOLTAGE - MIN_VOLTAGE) * 100;
    return static_cast<int>(battery);
}
