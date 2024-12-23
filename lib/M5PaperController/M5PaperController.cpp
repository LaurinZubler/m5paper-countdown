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
}

void M5PaperController::show(const int daysRemaining) {
    M5.RTC.getTime(&RTCtime);
    M5.RTC.getDate(&RTCDate);

    char timeStrbuff[64];
    sprintf(timeStrbuff, "%d/%02d/%02d %02d:%02d:%02d",
        RTCDate.year,
        RTCDate.mon,
        RTCDate.day,
        RTCtime.hour,
        RTCtime.min,
        RTCtime.sec
    );

    char timeStrbuff2[64];
    sprintf(timeStrbuff2, "Days remaining: %d", daysRemaining);

    canvas.drawString(timeStrbuff, 10, 10);
    canvas.drawString(timeStrbuff2, 10, 60);
    canvas.pushCanvas(0, 0, UPDATE_MODE_DU4);
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
