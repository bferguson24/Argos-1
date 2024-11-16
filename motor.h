#ifndef MOTOR_H
#define MOTOR_H

#include <Adafruit_PWMServoDriver.h>

//Class Definitions
class Motor{
public: 
  float maxAngle;
  float minAngle;
  float current_angle;

  Motor(int servo_pin, Adafruit_PWMServoDriver &driver, float max_angle, float min_angle);

  void setAngle(float thetaDeg);


private:
  int servoPin; 
  Adafruit_PWMServoDriver &driver; // Reference to the PWM driver
};

#endif 