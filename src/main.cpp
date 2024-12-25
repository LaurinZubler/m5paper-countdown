#include "CountdownTimer.h"
#include "M5PaperController.h"
#include "WiFiHelper.h"
#include "NTPHelper.h"
#include <M5EPD.h>

M5PaperController m5PaperController;
NTPHelper ntp;
WiFiHelper wifi;
CountdownTimer countdownTimer(2025, 10, 1);

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
    delay(1000 * 60 * 60); // 1h
    // delay(1000); // 1s
}
