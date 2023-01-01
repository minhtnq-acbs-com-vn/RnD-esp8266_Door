#include "../Headers/mqtt.h"

void setupMQTTConnection()
{
    client.setServer(mqttServer, port);
    client.setCallback(callback);
}

void callback(char *topic, byte *message, unsigned int length)
{
  Serial.println(topic);

  String strMsg;

  for (uint32_t i = 0; i < length; i++)
  {
    strMsg += (char)message[i];
  }

  Serial.println(strMsg);
  //***Insert code here to control other devices***
  if (strMsg == serverRequest)
  {
    responseState();
    publishConfirm();
  }
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