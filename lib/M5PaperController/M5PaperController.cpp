#include "M5PaperController.h"
#include <M5EPD.h>

M5EPD_Canvas canvas(&M5.EPD);

rtc_time_t RTCtime;
rtc_date_t RTCDate;

void M5PaperController::initialize(const tm& currentTime) {
    M5.begin();
    M5.EPD.SetRotation(90);
    M5.EPD.Clear(true);

    setSystemTime(currentTime);

    M5.RTC.begin();
    canvas.createCanvas(540, 960);
    canvas.setTextDatum(CC_DATUM);
    canvas.setTextSize(4);
    canvas.drawString("Noch", 540/2, 960/4);
    canvas.drawString("bis zur", 540/2, 960*0.75);
    canvas.drawString("Pensionierung", 540/2, 960*0.83);

    canvas.setTextSize(48);
    canvas.setTextDatum(TC_DATUM);
    canvas.drawString("Tage", 540/2, 960*0.52);

    canvas.pushCanvas(0, 0, UPDATE_MODE_DU);
}

void M5PaperController::updateScreen(const int daysRemaining) {
    // remaining days
    canvas.createCanvas(540, 960);
    canvas.setTextDatum(BC_DATUM);
    canvas.setTextSize(128);
    canvas.drawNumber(daysRemaining, 540/2, 960*0.48);
    canvas.pushCanvas(0, 0, UPDATE_MODE_DU);

    // update timestamp
    canvas.createCanvas(540, 960);
    canvas.setTextDatum(BR_DATUM);
    canvas.setTextSize(1);

    const tm now = getSystemTime();
    char strBuff[64];
    sprintf(strBuff, "%d-%02d-%02d %02d:%02d:%02d",
        now.tm_year + 1900, now.tm_mon + 1, now.tm_mday,
        now.tm_hour, now.tm_min, now.tm_sec
    );

    canvas.drawString(strBuff, 539, 950);
    canvas.pushCanvas(0, 0, UPDATE_MODE_DU);
}

tm M5PaperController::getSystemTime() {
    tm time;
    getLocalTime(&time);
    return time;
}

void M5PaperController::setSystemTime(const tm& currentTime) {
    RTCtime.hour = currentTime.tm_hour;
    RTCtime.min = currentTime.tm_min;
    RTCtime.sec = currentTime.tm_sec;
    M5.RTC.setTime(&RTCtime);

    RTCDate.year = currentTime.tm_year + 1900;
    RTCDate.mon = currentTime.tm_mon + 1;
    RTCDate.day = currentTime.tm_mday;
    M5.RTC.setDate(&RTCDate);
}
