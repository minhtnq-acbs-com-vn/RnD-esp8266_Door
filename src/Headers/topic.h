#ifndef TOPIC_H
#define TOPIC_H

// Setup topic
// From device
inline const char *topicDoorDevice = "Door/room1";
inline const char *topicDoorACK = "Door/room1/ACK";
// To device
inline const char *topicDoorServer = "Door/room1/server";

inline String topic[] = {topicDoorDevice, topicDoorACK, topicDoorServer};
inline String topicKey[] = {"subscribe", "ack", "publish"};

#endif