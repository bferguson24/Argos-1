#ifndef LEG_H
#define LEG_H

#include "motor.h"

class Leg{ 
public:   
float x,y,z;
float *d_cent_hip;
float *d_cent_foot; 

  Leg(Motor &j1, Motor &j2, Motor &j3, float *homeArray, int reflection_array[3], float *d_cent_hip, float *d_cent_foot);


    void incrementPosition(float dX,float dY,float dZ);

    void home();

    void setAngle(float theta1, float theta2, float theta3); 

    void IK(float x, float y, float z);

    void FK(float theta1, float theta2, float theta3);

private:

  Motor J1;
  Motor J2;
  Motor J3; 
  Motor* motorList[3];

  float homeX;
  float homeY;
  float homeZ;

  int reflection_array[6];
  float P_centroid_hip[3];
};

#endif 