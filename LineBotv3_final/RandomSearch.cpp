#include "RandomSearch.h"

RandomSearch::RandomSearch(Motor& m, Display& d, Sensor& lSensor, Sensor& rSensor)
    : motor(m), display(d), leftSensor(lSensor), rightSensor(rSensor) {
    lastDetectedTime = millis();
    searchDuration = 3000; // 3 seconds of no line before searching
}

void RandomSearch::update() {
    if (!leftSensor.isOnLine() && !rightSensor.isOnLine()) {
        if (millis() - lastDetectedTime >= searchDuration) {
            initiateSearch();
        }
    } else {
        lastDetectedTime = millis();  // Reset the timer if the line gets detected
    }
}

void RandomSearch::initiateSearch() {
    display.showStatus("S");
    motor.turnLeft();  // first turn left 
    delay(1000);
    if (leftSensor.isOnLine() || rightSensor.isOnLine()) {
        return; // found line go back
    }
    motor.turnRight();  // if still no line turn right
    delay(1000);
    if (!leftSensor.isOnLine() && !rightSensor.isOnLine()) {
        motor.stop();
        display.showStatus("E");  // Stop and display "E" for error if line is not found by random search
    }
}
