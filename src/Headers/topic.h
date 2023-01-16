#ifndef TOPIC_H
#define TOPIC_H

#include "api.h"

// Setup topic
// From device
inline const char *topicDoorDevice = "DoornPIR/room1";
inline const char *topicDoorACK = "DoornPIR/room1/ACK";
// To device
inline const char *topicDoorServer = "DoornPIR/room1/server";

inline String topic[] = {topicDoorDevice, topicDoorACK, topicDoorServer};

#endif