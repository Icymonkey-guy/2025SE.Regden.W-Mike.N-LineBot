#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include <Servo.h>

class Motor {
private:
    Servo servo1;    
    Servo servo2;    
    int pin1;        
    int pin2;        
    int min;    // Minimum back
    int max;    // Maximum forward

public:
    Motor(int servoPin1, int servoPin2, int minSpeed, int maxSpeed);

    void init();

    // all the stuff to move linebot
    void forward();
    void turnLeft();
    void turnRight();
    void turnBackRight();
    void turnBackLeft();
    void stop();
};

#endif