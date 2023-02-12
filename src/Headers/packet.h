#ifndef PACKET_H
#define PACKET_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "pin.h"
#include "topic.h"
#include "api.h"

// Setup string
inline String deviceDoorConfirmed = "deviceDoorConfirmed";
inline String devicePIRConfirmed = "devicePIRConfirmed";
inline String serverRequestDoor = "requestDoorStatus";
inline String serverRequestPIR = "requestPIRStatus";
inline String requestAPI = "requestAPI";

inline String ack[] = {deviceDoorConfirmed, devicePIRConfirmed};
inline String ackKey[] = {"door", "pir"};
inline String request[] = {serverRequestDoor, serverRequestPIR, requestAPI};
inline String requestKey[] = {"door", "pir", "api"};

String packToJson();

#endif