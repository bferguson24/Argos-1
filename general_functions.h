#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H

#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <stdint.h>

float analogClip(int AnalogPin, float deadzone);

void readRegister(uint8_t reg);

void multiPrint();
#endif