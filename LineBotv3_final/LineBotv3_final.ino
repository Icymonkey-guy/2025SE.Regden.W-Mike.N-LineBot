#include "Sensor.h"
#include "Motor.h"
#include "Display.h"
#include "RandomSearch.h"
#include "SharpTurn.h"

Sensor leftSensor(A3, 58); // pins and thresholds :(
Sensor rightSensor(A4, 47);

// Create Motor with pins and min/max speeds
Motor motor(8, 9, 700, 2300);

// Create Display 
Display display;

// Create RandomSearch and SharpTurn
RandomSearch randomSearch(motor, display, leftSensor, rightSensor);
SharpTurn sharpTurn(motor, display, leftSensor, rightSensor);

void setup() {
    motor.init();       // Init motors
    motor.stop();
    display.init();     // Init display
    delay(1000);        // give it all a little time to init
}

void loop() {
    bool leftOnLine = leftSensor.isOnLine();
    bool rightOnLine = rightSensor.isOnLine();

    randomSearch.update();  // Check if random search is needed

    if (leftOnLine && rightOnLine) {
        sharpTurn.handleSharpTurn();  // Handle sharp turn if needed
    } else if (!leftOnLine && !rightOnLine) {
        motor.forward();
        display.showStatus("F"); // goin forward
    } else if (leftOnLine) {
        motor.turnRight();
        display.showStatus("R"); // goin right
    } else if (rightOnLine) {
        motor.turnLeft();
        display.showStatus("L"); // goin left
    }
    delay(25); 
}
