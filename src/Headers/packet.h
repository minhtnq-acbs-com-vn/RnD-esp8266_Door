#ifndef PACKET_H
#define PACKET_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "pin.h"

// Setup string
inline String deviceDoorConfirmed = "deviceDoorConfirmed";
inline String devicePIRConfirmed = "devicePIRConfirmed";
inline String serverRequestDoor = "requestDoorStatus";
inline String serverRequestPIR = "requestPIRStatus";
inline String requestAPI = "requestAPI";

inline String topicDoorDeviceString = "DoornPIR/room1";
inline String topicDoorACKString = "DoornPIR/room1/ACK";
inline String topicDoorServerString = "DoornPIR/room1/server";

inline String topic[] = {topicDoorDeviceString, topicDoorACKString, topicDoorServerString};
inline String ack[] = {deviceDoorConfirmed, devicePIRConfirmed};
inline String request[] = {serverRequestDoor, serverRequestPIR, requestAPI};
inline int pin[] = {doorSensor, pirSensor};

const String apiHost = "https://perfect-cow-14.telebit.io/api/v1/device";
const String roomName = "room1";
const String deviceModule = "DoornPIR";
inline const String apiQuery = apiHost + "/" + String(ESP.getChipId()) + ":" + roomName + ":" + deviceModule;

String packToJson();

#endif