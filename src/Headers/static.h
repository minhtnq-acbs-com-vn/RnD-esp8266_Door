#ifndef STATIC_H
#define STATIC_H

#include <Arduino.h>

#include "client.h"
#include "topic.h"
#include "packet.h"
#include "pin.h"

int readState(int pin);
void publishResponse(String flag);
void publishDoorConfirm();
void responseDoorState();
void responsePIRState();
void publishPIRConfirm();

#endif