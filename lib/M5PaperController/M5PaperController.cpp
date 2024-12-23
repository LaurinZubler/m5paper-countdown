#include "M5PaperController.h"
#include <M5EPD.h>

M5EPD_Canvas canvas(&M5.EPD);

rtc_time_t RTCtime;
rtc_date_t RTCDate;


void M5PaperController::initialize() {
    M5.begin();
    M5.EPD.SetRotation(90);
    M5.EPD.Clear(true);
    M5.RTC.begin();
    canvas.createCanvas(540, 960);
    canvas.setTextSize(3);
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

tm M5PaperController::getCurrentTime() {
    rtc_time_t time;
    rtc_date_t date;

    M5.RTC.getTime(&time);
    M5.RTC.getDate(&date);

    tm currentTime = {time.sec, time.min, time.hour, date.day, date.mon, date.year - 1900};
    return currentTime;
}
