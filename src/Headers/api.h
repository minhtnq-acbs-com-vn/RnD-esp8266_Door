#ifndef API_H
#define API_H

#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "client.h"
#include "mqtt.h"
#include "packet.h"
#include "pin.h"
#include "topic.h"

inline const String apiHost = "https://rndaedss.ddns.net/api/v1/device";
inline const String roomName = "room1";
inline const String deviceModule = "Door";
inline const String deviceFunc[] = {"Door", "PIR"};
inline const String deviceName = String(ESP.getChipId());
inline const String apiQuery = apiHost + "/" + deviceName;

void sentDeviceInfo();
String getDeviceInfo();
void setupDeviceConfig();
void setupPacketConfig(DynamicJsonDocument doc);
void setupPin(DynamicJsonDocument doc);
void printChanges(String option);

#endif