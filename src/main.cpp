#include <Arduino.h>
#include "Headers/mqtt.h"
#include "Headers/static.h"
#include "Headers/wificustom.h"

void setup()
{
  // Init Serial console
  Serial.begin(9600);
  Serial.print("Connecting to WiFi");

  // Init wifi and mqtt
  wifiConnect();
  delay(500);
  setupMQTTConnection();
  delay(500);

  sentDeviceInfo();
  delay(500);
  setupDeviceConfig();
  // Setup pin mode
  pinMode(doorSensor, INPUT);
  pinMode(pirSensor, INPUT);
}

void loop()
{
  int value = digitalRead(pirSensor);
  Serial.println(value);
  delay(500);
  if (!client.connected())
  {
    mqttReconnect();
  }
  client.loop();
  wifiCheck();
}