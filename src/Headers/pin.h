#ifndef PIN_H
#define PIN_H

// Init pin
inline int doorSensor = D2;
inline int pirSensor = D3;

inline int pin[] = {doorSensor, pirSensor};
inline String pinKey[] = {"door", "pir"};

#endif