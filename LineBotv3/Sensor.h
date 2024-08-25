#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
private:
    int pin;           // Analog pin for the linesensors
    int threshold;     // Threshold value of black line

public:
    Sensor(int sensorPin, int sensorThreshold);
  
    int readValue();
    bool isOnLine();

};

#endif