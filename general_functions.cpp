#include "general_functions.h"


float analogClip(int AnalogPin, float deadzone){
  float val;
  float gain = 0.5;
  float maxAnalog = 1023.0;
  float minAnalog = 0.0;
  float meanAnalog = (maxAnalog + minAnalog)/2;
  float data = analogRead(AnalogPin);

  int upper_lim = meanAnalog + deadzone/2;
  int lower_lim = meanAnalog - (deadzone/2);

    //Delta 0
    if ((data <= upper_lim) && (data >= lower_lim)){
      val = 0.0;
    }

    //Delta Positive
    else if (data > upper_lim){
      val = (data-meanAnalog)/(maxAnalog - meanAnalog);
    }
      //Delta Positive
    else if (data < lower_lim){
      val = -(data-meanAnalog)/(minAnalog - meanAnalog);
    }
    else{
      Serial.println("Invalid Data");
    }
    return val = val * gain;
};


void readRegister(uint8_t reg){
  Wire.beginTransmission(PCA9685_I2C_ADDRESS);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(PCA9685_I2C_ADDRESS,1);

  if (Wire.available()){
    uint8_t value = Wire.read();
    Serial.print("Register 0x");
    Serial.print(reg, HEX);
    Serial.println(value,HEX);
  } else {
    Serial.println("No Data Received");
  }
}

