#ifndef DOG_H
#define DOG_H

#include "motor.h"
#include "leg.h"

class dog{
public: 
  dog(Leg &leg1, Leg &leg2, Leg &leg3, Leg &leg4);

  void home();

  void move(float x, float y, float z); 

  void rpyControl(float y, float b, float a);
  
  private:
  Leg leg1;
  Leg leg2;
  Leg leg3;
  Leg leg4;
  Leg *legs[4]; 
};
#endif 