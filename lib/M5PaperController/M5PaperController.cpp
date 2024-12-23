#include "M5PaperController.h"

M5EPD_Canvas canvas(&M5.EPD);

void M5PaperController::initialize() {
    M5.begin();
    M5.EPD.Clear(true);
}

void M5PaperController::update(int remainingDays) {
    M5.EPD.Clear(true);

    char displayText[50];
    snprintf(displayText, sizeof(displayText), "Days remaining\n %d", remainingDays);

    M5.begin();
//    M5.EPD.SetRotation(90);
    M5.EPD.Clear(true);
    M5.RTC.begin();
    canvas.createCanvas(540, 960);
    canvas.setTextSize(4);
    canvas.setTextColor(15);
    canvas.drawString(displayText, 100, 200);
    canvas.pushCanvas(0, 0, UPDATE_MODE_DU4);
}
