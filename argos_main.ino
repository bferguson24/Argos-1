
//Standard Libraries
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <stdint.h>
#include <math.h> 

//Argos Specific Libraries
#include "parameters.h"
#include "Motor.h"
#include "leg.h"
#include "dog.h"
#include "IMU.h"
#include "general_functions.h"

//Driver/Motor Objects
  Adafruit_PWMServoDriver driver1;

//Gyro Definition
  Adafruit_MPU6050 mpu1;
  IMU gyro(mpu1);


//Motors
  //Leg 1 Motor Definitions
    Motor motor1(0, driver1, 60, 120);
    Motor motor2(1, driver1, 110, 180);
    Motor motor3(2, driver1, 40, 140);

  //Leg 2 Motor Definitions
    Motor motor4(3, driver1, 60, 120);
    Motor motor5(4, driver1, 110, 180);
    Motor motor6(5, driver1, 40, 140);

  //Leg 3 Motor Definitions
    Motor motor7(6, driver1, 60, 120);
    Motor motor8(7, driver1, 110, 180);
    Motor motor9(8, driver1, 40, 140);

  //Leg 4 Motor Definitions
    Motor motor10(9 , driver1, 60, 120);
    Motor motor11(10, driver1, 110, 180);
    Motor motor12(11, driver1, 40, 140);

//LEGS
  //Leg 1 Definition
    Leg leg1(motor1,motor2,motor3,home_position,leg1_map,d_hip1,d_foot1);

  //Leg 2 Definition
    Leg leg2(motor4,motor5, motor6,home_position,leg2_map,d_hip2,d_foot2);

  //Leg 3 Definition
    Leg leg3(motor7,motor8,motor9,home_position,leg3_map,d_hip3,d_foot3);

  //Leg 4 Definition
    Leg leg4(motor10,motor11,motor12,home_position,leg4_map,d_hip4,d_foot4);

//ARGOS definition
  dog argos(leg1,leg2,leg3,leg4);


void setup() {
  
  Serial.begin(9600); 

//Driver init 
  driver1.begin();
  driver1.setPWMFreq(50); //Hz

//IMU init
  gyro.init();

//argos init
  argos.home();

  delay(10);
  

// motor1.setAngle(90);
// motor2.setAngle(45);
// motor3.setAngle(90);


// motor4.setAngle(90);
// motor5.setAngle(135);
// motor6.setAngle(90);

// motor7.setAngle(90);
// motor8.setAngle(45);
// motor9.setAngle(90);

// motor10.setAngle(90);
// motor11.setAngle(135);
// motor12.setAngle(90);
}

void loop() {


// if (digitalRead(8) == 1){
//     //Serial.println("ON");
//     leg1.home();
//   }
// else{
//   //Serial.println("Off");
//   }

// readRegister(0x00);
// float droll = analogClip(A1,30);
// float dpitch = analogClip(A0,30); 
// float dyaw = analogClip(A2,30);

// roll = roll + droll;
// pitch = pitch + dpitch;
// yaw = yaw + dyaw;

// float roll = 0;
// float pitch = 0;
// float yaw = 45; 
// argos.rpyControl(roll,pitch,yaw);

// Serial.print("Roll = ");
// Serial.print(roll);
// Serial.print("  ");

// Serial.print("Pitch = ");
// Serial.print(pitch);
// Serial.print("  ");

// Serial.print("Yaw = ");
// Serial.print(yaw);
// Serial.println("  "); 

// Serial.print(joyValx);
// Serial.print("  ");
// Serial.print(joyValy);
// Serial.print("  ");
// Serial.println(joyValz);

// leg1.incrementPosition(joyValx,joyValy,joyValz);
// leg2.incrementPosition(joyValx,joyValy,joyValz);
// leg3.incrementPosition(joyValx,joyValy,joyValz);
// leg4.incrementPosition(joyValx,joyValy,joyValz);








}
 