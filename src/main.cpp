#include <Arduino.h>
#include <SmartWifi.h>    //ESP8266-12F智能组网
#include <PubSubClient.h> //MQTT协议SDK
#include <ArduinoJson.h>  //Arduion的json数据库
#include <CarController.h>

#define MQTT_SERVICE_IP "192.168.1.106"
#define MQTT_SERVICE_PORT 61613
#define MQTT_USERNAME "admin"
#define MQTT_PASSWORD "password"
//定义MQTT订阅接受消息
#define TOPIC_IN_MOVE "car/move" //小车移动指令
#define PAYLOAD_MOVE_
//定义MQTT订阅发送消息

//Wifi相关
SmartWifi wifi;

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient); //MQTT连接使用的客户端

CarMove car(D0, D1, D2, D3);
void carMove(String);
//MQTT相关
/* MQTT接受消息回调函数 */
void mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String body = "";
    for (unsigned int i = 0; i < length; i++)
    {
        body += (char)payload[i];
    }
    Serial.print("Body is : ");
    Serial.println(body);
    if (strcmp(topic, TOPIC_IN_MOVE) == 0)
    { //收到移动的消息
        carMove(body);
    }
    body = "";
}

/* 重新连接MQTT服务器 */
void reConnectMQTT()
{
    while (!mqttClient.connected())
    {
        Serial.print("Start attempting connection MQTT service ");
        Serial.print(MQTT_SERVICE_IP);
        Serial.println(", Please wait...");
        if (mqttClient.connect("ESP8266-12FCarClient", MQTT_USERNAME, MQTT_PASSWORD))
        {
            //连接成功  订阅消息
            Serial.println("********** Connect to MQTT service Suceess**********");
            //订阅输入主题
            mqttClient.subscribe(TOPIC_IN_MOVE);
        }
        else
        {
            // 连接失败，等待5秒重试
            Serial.print("Connect to MQTT service ");
            Serial.print(MQTT_SERVICE_IP);
            Serial.print(" failed, status is : ");
            Serial.print(mqttClient.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void setup()
{
    // put your setup code here, to run once:
    //初始化wifi
    wifi.init();
    mqttClient.setServer(MQTT_SERVICE_IP, MQTT_SERVICE_PORT);
    mqttClient.setCallback(mqttCallback);
}

void loop()
{
    // put your main code here, to run repeatedly:
    //wifi断网检测
    wifi.loop();

    //服务器连接效验
    if (!mqttClient.connected())
    {
        reConnectMQTT();
    }
    mqttClient.loop();
}

void carMove(String body)
{
    if (String("Forward").compareTo(body) == 0)
    {
        Serial.println("Forward");
        car.forward();
    }
    else if (String("Back").compareTo(body) == 0)
    {
        Serial.println("Back");
        car.back();
    }
    else if (String("Left").compareTo(body) == 0)
    {
        Serial.println("Left");
        car.left();
    }
    else if (String("Right").compareTo(body) == 0)
    {
        Serial.println("Right");
        car.right();
    }
    else
    {
        Serial.println("Stop");
        car.stop();
    }
}