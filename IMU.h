#ifndef IMU_H
#define IMU_H

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>



class IMU{
public: 
float roll, pitch, yaw;
  IMU(Adafruit_MPU6050 &mpu);
 
  
  void init();

  void rollpitchyaw();

private: 
Adafruit_MPU6050 mpu; 
}; 

#endif