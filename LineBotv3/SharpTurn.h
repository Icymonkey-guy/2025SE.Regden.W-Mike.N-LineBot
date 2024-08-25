#ifndef SHARPTURN_H
#define SHARPTURN_H

#include <Arduino.h>
#include "Motor.h"
#include "Display.h"
#include "Sensor.h"

class SharpTurn {
private:
    Motor& motor;
    Display& display;
    Sensor& leftSensor;
    Sensor& rightSensor;

public:
    SharpTurn(Motor& m, Display& d, Sensor& lSensor, Sensor& rSensor);
    void handleSharpTurn();
};

#endif
