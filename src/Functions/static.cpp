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
  int state = readState(doorSensor);
  if (state == 1)
    publishResponse("1");
  if (state == 0)
    publishResponse("0");
  publishDoorConfirm();
}

void responsePIRState()
{
  int state = readState(pirSensor);
  if (state == 1)
    publishResponse("1");
  if (state == 0)
    publishResponse("0");
  publishPIRConfirm();
}

void publishPIRConfirm()
{
  client.publish(topicDoorACK, devicePIRConfirmed.c_str());
}