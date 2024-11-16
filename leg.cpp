#include "leg.h"
#include "parameters.h"



Leg::Leg(Motor &j1, Motor &j2, Motor &j3, float *homeArray, int reflection_array[3], float *d_cent_hip, float *d_cent_foot)
  : J1(j1), J2(j2), J3(j3), x(homeArray[0]), y(homeArray[1]), z(homeArray[2]) {
      homeX = homeArray[0];
      homeY = homeArray[1];
      homeZ = homeArray[2];    

      x = homeX;
      y = homeY;
      z = homeZ;

  
      motorList[0] = &J1;
      motorList[1] = &J2;
      motorList[2] = &J3;

      for (int i = 0; i < 6; i++)
        this->reflection_array[i] = reflection_array[i];

      this->d_cent_hip = d_cent_hip;  
      this->d_cent_foot = d_cent_foot;  
    }

  void Leg::incrementPosition(float dX,float dY,float dZ){
    x = x + dX;
    y = y + dY;
    z = z + dZ;
    Serial.print(x);
    Serial.print("  ");
    Serial.print(y);
    Serial.print("  ");
    Serial.println(z);

    //Need Limits on Workspace Here
    IK(x,y,z);
  }

  void Leg::home() {
    x = homeX;
    y = homeY;
    z = homeZ;

    Serial.print(x);
    Serial.print("  ");
    Serial.print(y);
    Serial.print("  ");
    Serial.println(z);
    IK(x,y,z);
  }

  void Leg::setAngle(float theta1, float theta2, float theta3){
    // workspaceCheck(theta1,theta2,theta3);

    J1.setAngle(theta1);
    J2.setAngle(theta2);
    J3.setAngle(theta3);
  }

  void Leg::IK(float x, float y, float z){
    //Mirror Z Component Only:
    
    // Serial.println(z);

    float theta1 = 90 - (atan2((sqrt(z*z + y*y - d1*d1)),d1) - (PI/2) + atan2(z,y)) * (180.0/PI);
    float theta2 = (PI - atan2(sqrt(z*z + y*y -d1*d1),x) - acos( (l1*l1 - l2*l2 + (x*x + z*z + y*y -d1*d1))/(-2*l1*sqrt(x*x + z*z + y*y - d1*d1)))) * (180.0/PI);
    float theta3 = (PI - acos((x*x + z*z + y*y -d1*d1 - l1*l1 - l2*l2) / (-2*l1*l2))) * (180.0/PI);

    //Workspace Boundary Check

    theta1 = reflection_array[3] * abs((reflection_array[0]*180 - theta1));
    theta2 = abs((reflection_array[1]*180 - theta2 * reflection_array[4]));
    theta3 = reflection_array[5] * abs((reflection_array[2]*180 - theta3));


  // Serial.print(theta1);
  // Serial.print("  ");
  // Serial.print(theta2);
  // Serial.print("  ");
  // Serial.println(theta3);
  // Serial.print(theta1);
  // Serial.print("  ");
  // Serial.print(theta2);
  // Serial.print("  ");
  //  Serial.println(theta3);
  // theta1 = 90;
  // theta2 = 135;
  // theta3 = 90;
    setAngle(theta1,theta2,theta3);
  } 

  void Leg::FK(float theta1, float theta2, float theta3){
  }

  