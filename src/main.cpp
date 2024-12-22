#include "CountdownTimer.h"
#include "M5PaperController.h"

CountdownTimer countdownTimer(2024, 12, 25);
M5PaperController m5PaperController;

void setup() {
    m5PaperController.initialize();
}

void loop() {
    const int daysRemaining = countdownTimer.getDaysRemaining();
    m5PaperController.update(daysRemaining);
    delay(86400000); // 24 h
}
