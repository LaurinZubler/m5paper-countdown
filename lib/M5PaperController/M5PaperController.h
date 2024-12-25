#ifndef M5PAPERCONTROLLER_H
#define M5PAPERCONTROLLER_H

#include <ctime>

class M5PaperController {

static void setupTime();
static int getBatteryPercentage();

public:
void setSystemTime(const tm& currentTime);
    void initialize(const tm& currentTime);
    void updateScreen(int daysRemaining);
    void sleep(int seconds);
    tm getSystemTime();
};

#endif // M5PAPERCONTROLLER_H
