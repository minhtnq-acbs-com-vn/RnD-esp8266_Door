#include "../Headers/api.h"

void sentDeviceInfo()
{
    HTTPClient http;
    String payload = "";
    http.begin(secureClient, apiHost);
    String json = packToJson();
    Serial.println(json);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("userid", userID);
    int httpCode = http.POST(json);
    Serial.println(http.errorToString(httpCode));
    while (httpCode != 200)
    {
        http.end();
        delay(10000);
        http.begin(secureClient, apiHost);
        String json = packToJson();
        http.addHeader("Content-Type", "application/json");
        http.addHeader("userid", userID);
        int httpCode = http.POST(json);
        Serial.println(http.errorToString(httpCode));
        if (httpCode == 200)
            break;
    }

    // Check the returning code
    payload = http.getString(); // Get the request response payload
    Serial.println(payload);    // Print the response payload

    http.end();
}

String getDeviceInfo()
{
    HTTPClient http;
    String payload = "";
    http.begin(secureClient, apiQuery);
    http.addHeader("userid", userID);

    int httpCode = http.GET();
    Serial.println(http.errorToString(httpCode));
    while (httpCode != 200)
    {
        http.end();
        delay(10000);
        http.begin(secureClient, apiQuery);
        http.addHeader("userid", userID);
        int httpCode = http.GET();
        Serial.println(http.errorToString(httpCode));
        if (httpCode == 200)
            break;
    }
    // Check the returning code
    payload = http.getString(); // Get the request response payload

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
    deviceDoorConfirmed = doc["ack"]["door"].as<String>();
    devicePIRConfirmed = doc["ack"]["pir"].as<String>();
    serverRequestDoor = doc["request"]["door"].as<String>();
    serverRequestPIR = doc["request"]["pir"].as<String>();
    requestAPI = doc["request"]["api"].as<String>();
}

void setupPin(DynamicJsonDocument doc)
{
    doorSensor = doc["pin"]["door"].as<int>();
    pirSensor = doc["pin"]["pir"].as<int>();
}

void printChanges(String option)
{

    for (auto &element : ack)
    {
        Serial.println(element);
    }
    for (auto &element : request)
    {
        Serial.println(element);
    }

    for (auto &element : pin)
    {
        Serial.println(element);
    }
}