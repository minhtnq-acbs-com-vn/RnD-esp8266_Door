#ifndef PACKET_H
#define PACKET_H

#include <Arduino.h>

// Setup string
inline String deviceDoorConfirmed = "deviceDoorConfirmed";
inline String devicePIRConfirmed = "devicePIRConfirmed";
inline String serverRequestDoor = "requestDoorStatus";
inline String serverRequestPIR = "requestPIRStatus";
inline String requestAPI = "requestAPI";

const String apiHost = "https://192.168.68.107:5500/api/v1/device/";
const String roomName = "room1";
const String deviceModule = "DoornPIR";
inline const String apiQuery = apiHost + String(ESP.getChipId()) + ":" + roomName + ":" + deviceModule;

#endif