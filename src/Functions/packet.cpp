#include "../Headers/packet.h"

String packToJson()
{
    DynamicJsonDocument doc(1024);
    doc["roomName"] = roomName;
    doc["deviceModule"] = deviceModule;
    JsonArray dataTopic = doc.createNestedArray("topic");
    for (auto &element : topic)
    {
        dataTopic.add(element);
    }
    JsonArray dataACK = doc.createNestedArray("ack");
    for (auto &element : ack)
    {
        dataACK.add(element);
    }
    JsonArray dataRequest = doc.createNestedArray("request");
    for (auto &element : request)
    {
        dataRequest.add(element);
    }
    String json;
    serializeJson(doc, json);
    return json;
}