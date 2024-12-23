#include "NTPController.h"
#include <M5EPD.h>
#include <ctime>

const int MET = 3600 * 1;  // MET is UTC+1
const int DST = 3600 * 1;  // Daylight Saving Time adds another +1 hour

tm NTPController::getTime() {
    Serial.println("Syncing time with NTP...");
    configTime(MET, DST, "pool.ntp.org", "time.nist.gov");

    tm currentTime;
    Serial.println("Waiting for NTP time sync...");
    while (!getLocalTime(&currentTime)) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("\nTime synchronized!");
    Serial.println(&currentTime, "%Y-%m-%dT%H:%M:%S");
    return currentTime;
}