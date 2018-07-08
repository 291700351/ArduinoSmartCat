#ifndef _SMART_WIFI_H
#define _SMART_WIFI_H

#include <ESP8266WiFi.h>

class SmartWifi
{
  public:
    void init();
    bool attemptConnect();

    void smartConfig();

    void loop();

    uint8_t status();
};

#endif