#include "WiFiHelper.h"
#include "config.h"
#include <M5EPD.h>
#include <WiFi.h>

void WiFiHelper::connect() {
    Serial.println("Connecting to WiFi...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
}