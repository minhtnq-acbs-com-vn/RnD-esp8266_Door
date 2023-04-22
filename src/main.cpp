#include <Arduino.h>
#include "Headers/mqtt.h"
#include "Headers/static.h"
#include "Headers/wificustom.h"

void setup()
{
  // Init Serial console
  Serial.begin(9600);
  Serial.print("Connecting to WiFi");
  delay(500);

  // Setup pin mode
  pinMode(doorSensor, INPUT_PULLUP);
  pinMode(pirSensor, INPUT);

  // Init wifi and mqtt
  wifiConnect();
  setupMQTTConnection();

  sentDeviceInfo();
  setupDeviceConfig();
}

void loop()
{
  if (!client.connected())
  {
    mqttReconnect();
  }
  client.loop();
  wifiCheck();
}