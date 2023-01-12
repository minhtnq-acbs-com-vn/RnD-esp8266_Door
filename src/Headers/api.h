#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "client.h"
#include "mqtt.h"
#include "packet.h"
#include "pin.h"
#include "topic.h"

String responseAPI();
void setupDeviceConfig();
void setupMQTTConfig(DynamicJsonDocument doc);
void setupPacketConfig(DynamicJsonDocument doc);
void setupPin(DynamicJsonDocument doc);
void setupTopic(DynamicJsonDocument doc);
void printChanges(String option);