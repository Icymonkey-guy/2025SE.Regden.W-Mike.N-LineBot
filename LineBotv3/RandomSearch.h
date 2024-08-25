#ifndef RANDOMSEARCH_H
#define RANDOMSEARCH_H

#include <Arduino.h>
#include "Motor.h"
#include "Display.h"
#include "Sensor.h"

class RandomSearch {
private:
    Motor& motor;
    Display& display;
    Sensor& leftSensor;
    Sensor& rightSensor;
    unsigned long lastDetectedTime;
    unsigned long searchDuration;

public:
    RandomSearch(Motor& m, Display& d, Sensor& lSensor, Sensor& rSensor);
    void update(); //check if search is needed
    void initiateSearch(); //start searching
    bool checkTimeExceeded();
};

#endif
