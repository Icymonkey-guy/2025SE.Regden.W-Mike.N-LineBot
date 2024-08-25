#include "Sensor.h"

Sensor::Sensor(int sensorPin, int sensorThreshold) {
    this->pin = sensorPin;
    this->threshold = sensorThreshold;
}

int Sensor::readValue() {
    return analogRead(pin); // get sensor valye
}

bool Sensor::isOnLine() {
    return (analogRead(pin) <= threshold); // find line
}