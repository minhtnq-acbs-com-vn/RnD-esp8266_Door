#include <Arduino.h>
#include <Headers/Network/mqtt.h>
#include <Headers/Network/client.h>
#include <Headers/Network/topic.h>
#include <Headers/GPIO/pin.h>
#include <Headers/Command_Variable/packet.h>

// Function declaration
// STATIC
int readState(int pin);
void publishFlag(String flag);
void publishConfirm();
// NETWORK
void wifiConnect();
void mqttReconnect();
void wifiCheck();
void failedReconnect();
// DATA HANDLING
void callback(char *topic, byte *message, unsigned int length);
void responseState();

void setup()
{
  // Init Serial console
  Serial.begin(9600);
  Serial.print("Connecting to WiFi");

  // Init wifi and mqtt
  

  wifiConnect();
  client.setServer(mqttServer, port);
  client.setCallback(callback);

  // Setup pin mode
  pinMode(doorSensor, INPUT);
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

/////////////STATIC FUNCTION/////////////
// Get data from sensor
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
/////////////STATIC FUNCTION/////////////

/////////////NETWORK FUNCTION/////////////
// Connect wifi
void wifiConnect()
{
  wifiManager.setTimeout(180);
  if (!wifiManager.autoConnect("AutoConnectAP"))
  {
    Serial.println("failed to connect and hit timeout");
    delay(3000);
    ESP.reset();
    delay(5000);
  }
  Serial.println("connected...yeey :)");
}

void wifiCheck()
{
  uint32_t notConnectedCounter = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    notConnectedCounter++;
    if (notConnectedCounter > 300)
    { // Reset board if not connected after 15s
      Serial.println("Resetting due to Wifi not connecting...");
      WiFi.reconnect();
      // failedReconnect();
    }
  }
}

void failedReconnect()
{
  delay(10000);                  // let esp take time reconnect
  for (int i = 0; i < 6000; i++) // wait for 5 minutes before reset esp
  {
    delay(500);
  }
  if (WiFi.status() != WL_CONNECTED)
  {
    ESP.restart();
  }
}

// Connect to mqtt broker and subscribe specific topic(s)
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
/////////////NETWORK FUNCTION/////////////

/////////////DATA HANDLING FUNCTION/////////////
// Handle mqtt packet here
void callback(char *topic, byte *message, unsigned int length)
{
  Serial.println(topic);

  String strMsg;

  for (unsigned int i = 0; i < length; i++)
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

// Sent response
void responseState()
{
  int state = readState(doorSensor);
  if (state == 1)
    publishFlag(lockedState);
  else if (state == 0)
    publishFlag(unlockedState);
}
/////////////DATA HANDLING FUNCTION/////////////
