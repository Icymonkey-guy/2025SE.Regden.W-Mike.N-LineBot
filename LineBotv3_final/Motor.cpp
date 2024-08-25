#include "Motor.h"

Motor::Motor(int servoPin1, int servoPin2, int minSpeed, int maxSpeed) 
    : pin1(servoPin1), pin2(servoPin2), min(minSpeed), max(maxSpeed) {}

// Initialization method
void Motor::init() {
    servo1.attach(pin1, min, max);
    servo2.attach(pin2, min, max);
}



void Motor::forward() {
    servo1.writeMicroseconds(1620); //forwrad
    servo2.writeMicroseconds(1390);  
}
void Motor::turnLeft() {
    servo1.writeMicroseconds(1505);  // Stop left motor
    servo2.writeMicroseconds(1390);  // forward right motor
}

// Turn right
void Motor::turnRight() {
    servo1.writeMicroseconds(1620);  // forward left motor
    servo2.writeMicroseconds(1505);  // Stop right motor
}

void Motor::turnBackLeft() {
    servo1.writeMicroseconds(1505);  // Stop left motor
    servo2.writeMicroseconds(1530);  // back right motor
}

// Turn right
void Motor::turnBackRight() {
    servo1.writeMicroseconds(1480);  // back left motor
    servo2.writeMicroseconds(1505);  // Stop right motor
}

// Stop
void Motor::stop() {
    servo1.writeMicroseconds(1505);  // stopped
    servo2.writeMicroseconds(1505); 
}