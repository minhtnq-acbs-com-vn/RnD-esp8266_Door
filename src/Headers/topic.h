#ifndef TOPIC_H
#define TOPIC_H

// Setup topic
// From device
inline const char *topicDoorDevice = "640ee59066f4b889269ff405/Door/G2";
inline const char *topicDoorACK = "640ee59066f4b889269ff405/Door/G2/ACK";
// To device
inline const char *topicDoorServer = "640ee59066f4b889269ff405/Door/G2/server";

inline String topic[] = {topicDoorServer, topicDoorACK, topicDoorDevice};
inline String topicKey[] = {"subscribe", "ack", "publish"};

#endif