#include "../Headers/static.h"

int readState(int pin)
{
  return digitalRead(pin);
}

// Use to publish a string to a specific topic
void publishResponse(const String flag)
{
  client.publish(topicDoorDevice, flag.c_str());
}

// Use to confirm with server
void publishDoorConfirm()
{
  client.publish(topicDoorACK, deviceDoorConfirmed.c_str());
}

void responseDoorState()
{
  publishResponse("door:" + String(readState(doorSensor)));
  Serial.println(String(readState(doorSensor)));
  publishDoorConfirm();
}

void publishPIRConfirm()
{
  client.publish(topicDoorACK, devicePIRConfirmed.c_str());
}

void responsePIRState()
{
  publishResponse("pir:" + String(readState(pirSensor)));
  Serial.println(String(readState(pirSensor)));
  publishPIRConfirm();
}
