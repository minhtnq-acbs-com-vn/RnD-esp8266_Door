#include "../Headers/api.h"

void sentDeviceInfo()
{
    HTTPClient http;
    String payload = "";
    http.begin(secureClient, apiHost);
    String json = packToJson();
    Serial.println(json);
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST(json);
    Serial.println(http.errorToString(httpCode));
    // // Check the returning code
    payload = http.getString(); // Get the request response payload
    Serial.println(payload);    // Print the response payload

    http.end();
}

String getDeviceInfo()
{
    HTTPClient http;
    String payload = "";
    http.begin(secureClient, apiQuery);

    int httpCode = http.GET();
    Serial.println(http.errorToString(httpCode));
    while (httpCode != 200)
    {
        http.end();
        delay(10000);
        http.begin(secureClient, apiQuery);
        int httpCode = http.GET();
        Serial.println(http.errorToString(httpCode));
        if (httpCode == 200)
            break;
    }
    // Check the returning code
    payload = http.getString(); // Get the request response payload
    Serial.println(payload);    // Print the response payload

    http.end();
    return payload;
}

void setupDeviceConfig()
{
    String payload = getDeviceInfo();
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, payload);
    if (error)
        Serial.println(error.f_str());
    else
    {
        setupPacketConfig(doc);
        setupPin(doc);
    }
}

void setupPacketConfig(DynamicJsonDocument doc)
{
    printChanges("packet");
    deviceDoorConfirmed = doc["deviceDoorConfirmed"].as<String>();
    devicePIRConfirmed = doc["devicePIRConfirmed"].as<String>();
    serverRequestDoor = doc["serverRequestDoor"].as<String>();
    serverRequestPIR = doc["serverRequestPIR"].as<String>();
    requestAPI = doc["requestAPI"].as<String>();
    printChanges("packet");
}

void setupPin(DynamicJsonDocument doc)
{
    printChanges("pin");
    doorSensor = doc["doorSensor"].as<int>();
    pirSensor = doc["pirSensor"].as<int>();
    printChanges("pin");
}

void printChanges(String option)
{
    if (option == "packet")
    {
        Serial.println(deviceDoorConfirmed);
        Serial.println(devicePIRConfirmed);
        Serial.println(serverRequestDoor);
        Serial.println(serverRequestPIR);
        Serial.println(requestAPI);
    }
    else if (option == "pin")
    {
        Serial.println(doorSensor);
        Serial.println(pirSensor);
    }
}