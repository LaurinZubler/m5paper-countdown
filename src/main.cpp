#include "CountdownTimer.h"
#include "M5PaperController.h"
#include "WiFiController.h"
#include "NTPController.h"
#include <M5EPD.h>

M5PaperController m5PaperController;
NTPController ntp;
WiFiController wifi;
CountdownTimer countdownTimer(2025, 10, 1);

void setup() {
    wifi.connect();
    const tm currentTime = ntp.getTime();
    m5PaperController.initialize(currentTime);
}

void loop() {
    tm now = m5PaperController.getSystemTime();
    const int days = countdownTimer.getDaysRemaining(now);
    m5PaperController.show(days);
    // delay(1000 * 60); // 1min
    delay(1000); // s
}
