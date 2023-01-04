#include "../Headers/static.h"

int readState(int pin)
{
  return digitalRead(pin);
}

// Use to publish a string to a specific topic
void publishFlag(const String flag)
{
  client.publish(topicDoorDevice, flag.c_str());
}

// Use to confirm with server
void publishConfirm()
{
  client.publish(topicDoorACK, deviceConfirmed.c_str());
}

void responseState()
{
  int state = readState(doorSensor);
  if (state == 1)
    publishFlag("1");
  else if (state == 0)
    publishFlag("0");
}

void responsePIRState()
{
  int state = readState(pirSensor);
  if (state == 1)
    publishFlag("1");
  else if (state == 0)
    publishFlag("0");
}

void publishPIRConfirm()
{
  client.publish(topicDoorACK, devicePIRConfirmed.c_str());
}