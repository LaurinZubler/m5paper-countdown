#include "CountdownTimer.h"
#include "M5PaperController.h"
#include "WiFiHelper.h"
#include "NTPHelper.h"
#include <M5EPD.h>

M5PaperController m5PaperController;
NTPHelper ntp;
WiFiHelper wifi;
CountdownTimer countdownTimer(2025, 9, 11);

void setup() {
    wifi.connect();
    const tm currentTime = ntp.getTime();
    m5PaperController.initialize(currentTime);
    wifi.disconnect();
}

void loop() {
    const tm now = m5PaperController.getSystemTime();
    const int days = countdownTimer.getDaysRemaining(now);
    m5PaperController.updateScreen(days);

    constexpr int delaySeconds = 60 * 60 * 8; // 8h
    m5PaperController.sleep(delaySeconds);
    delay(delaySeconds * 1000);
}
