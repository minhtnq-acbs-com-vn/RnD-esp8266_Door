#ifndef MQTT_H
#define MQTT_H

#include "client.h"
#include "topic.h"
#include "packet.h"
#include "static.h"

// Setup MQTT
inline const char *mqttServer = "192.168.68.116";
inline const char *mqttUsername = "pi";
inline const char *mqttPassword = "Kou-chan1153";
inline int port = 1883;

inline const char *mqttClientID = String(ESP.getChipId()).c_str();

void setupMQTTConnection();
void callback(char *topic, byte *message, unsigned int length);
void mqttReconnect();

#endif