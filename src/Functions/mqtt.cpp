#include "../Headers/mqtt.h"

void setupMQTTConnection()
{
  secureClient.setInsecure();
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
}

void callback(char *topic, byte *message, unsigned int length)
{
  String strMsg;
  for (uint32_t i = 0; i < length; i++)
  {
    strMsg += (char)message[i];
  }
  Serial.println(strMsg);
  requestFilter(strMsg);
}

void requestFilter(String request)
{
  if (request == serverRequestDoor)
    responseDoorState();
  if (request == serverRequestPIR)
    responsePIRState();
  if (request == requestAPI)
    setupDeviceConfig();
}

void mqttReconnect()
{
  while (!client.connected())
  {
    Serial.println("Attemping MQTT connection...");
    if (client.connect(mqttClientID, mqttUsername, mqttPassword))
    {
      Serial.println("Connected");

      //***Subscribe all topic you need***
      client.subscribe(topicDoorServer);
    }
    else
    {
      Serial.println("try again in 5 seconds");
      delay(5000);
    }
  }
}