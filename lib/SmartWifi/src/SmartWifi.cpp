#include "SmartWifi.h"
int LED = D4;

void SmartWifi::init()
{
    Serial.begin(9600); 
}
bool SmartWifi::attemptConnect()
{
    WiFi.begin();
    Serial.print("Attempt Connect To WiFi,Pleast Wait");
    for (int i = 0; i < 20; i++)
    {
        int wstatus = WiFi.status();
        if (wstatus == WL_CONNECTED)
        { 
            Serial.println();
            Serial.println("********** WiFi Attempt Connect Success **********");
            Serial.printf("WiFi ssid is : %s", WiFi.SSID().c_str());
            Serial.println();
            Serial.printf("WiFi password is : %s", WiFi.psk().c_str());
            Serial.println();
            Serial.print("WiFi ip address is : ");
            Serial.println(WiFi.localIP());
            return true;
        }
        else
        {
            Serial.print(".");
            delay(1000);
        }
    }
    Serial.println();
    Serial.println("********** WiFi Attempt Connect Faild! **********");
    return false;
}

void SmartWifi::smartConfig()
{
    WiFi.mode(WIFI_STA);
    Serial.println();
    Serial.println("********** Waiting for Smartconfig WiFi **********");
    WiFi.beginSmartConfig();
    while (true)
    {
        Serial.print("."); 
        if (WiFi.smartConfigDone())
        { 
            WiFi.setAutoConnect(true); // 设置自动连接
            Serial.println();
            Serial.println("********** WiFi Smart Connect Success **********");
            Serial.printf("WiFi ssid is : %s", WiFi.SSID().c_str());
            Serial.println();
            Serial.printf("WiFi password is : %s", WiFi.psk().c_str());
            Serial.println();
            Serial.print("WiFi ip address is : ");
            Serial.println(WiFi.localIP());
            break;
        }
        delay(1000); // 这个地方一定要加延时，否则极易崩溃重启
    }
}

void SmartWifi::loop()
{
    if (WiFi.status() == WL_NO_SSID_AVAIL)
    {
        Serial.println();
        Serial.println("No SSID Contected");
        //需要重新配置
        if (!attemptConnect())
        {
            smartConfig();
        }
    }
}

uint8_t SmartWifi::status()
{
    return WiFi.status();
}
