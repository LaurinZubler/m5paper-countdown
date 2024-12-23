#include <DateUtils.h>

#include "CountdownTimer.h"
#include "M5PaperController.h"

CountdownTimer countdownTimer(2024, 12, 25);
M5PaperController m5PaperController;

void setup() {
    m5PaperController.initialize();
}

void loop() {
    const tm now = m5PaperController.getCurrentTime();

    const int daysRemaining = countdownTimer.getDaysRemaining(now);
    m5PaperController.show(daysRemaining);

    int secondsTillMidnight = DateUtils::getSecondsUntilMidnight(now);
    secondsTillMidnight += 60; // add 1 min, just to be sure :)
    delay(secondsTillMidnight);
}
