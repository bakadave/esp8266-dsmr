#ifndef _MQTT_PUB
#define _MQTT_PUB

#define MQTT_SOCKET_TIMEOUT 5
#pragma once
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <vector>
#include "PubSubClient.h"
#include "WiFiClient.h"
#include "Logger.h"

#define RECONNECT_TIMEOUT 15000
#define MQTT_CLEAN_SESSION 1    // 0 = No clean session, 1 = Clean session (default)
#define WILL_MESSAGE "Offline"  //LWT message

extern bool hasMQTT;
extern bool hasWIFI;

class MQTTPublisher
{
  private:
    Logger logger;
    bool _debugMode;
    String _identifier;
    bool isStarted;
    uint32_t lastConnectionAttempt = 0; // last reconnect
    uint32_t lastUpdateMqtt; // last data send

    bool reconnect();
    String getTopic(String name);

  public:
    MQTTPublisher(String identifier);
    MQTTPublisher();

    void start();
    void stop();
    void handle();
    bool publish(String topic, String msg, bool addIdentifier);
};

#endif
