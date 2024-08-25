#include "SharpTurn.h"

SharpTurn::SharpTurn(Motor& m, Display& d, Sensor& lSensor, Sensor& rSensor)
    : motor(m), display(d), leftSensor(lSensor), rightSensor(rSensor) {}

void SharpTurn::handleSharpTurn() {
    if (leftSensor.isOnLine() && rightSensor.isOnLine()) {
        if (leftSensor.isOnLine()) {
            display.showStatus("r"); 
            motor.turnBackRight(); //turn back right until only right sensor sees line
        } else {
            display.showStatus("l");
            motor.turnBackLeft(); // or the other way
        }
        delay(250);
    }
}
