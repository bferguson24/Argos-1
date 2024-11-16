#include "Motor.h"


Motor::Motor(int servo_pin, Adafruit_PWMServoDriver &driver, float max_angle, float min_angle)
  : servoPin(servo_pin), driver(driver), maxAngle(max_angle), minAngle(min_angle) {}

void Motor::setAngle(float thetaDeg){
  float counts = (((2.0/180.0 * thetaDeg) + 0.5) * (4096.0/20));
  driver.setPWM(servoPin,0,counts);
  current_angle = thetaDeg;
} 