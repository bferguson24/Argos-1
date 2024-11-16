#include "dog.h"


  dog::dog(Leg &leg1, Leg &leg2, Leg &leg3, Leg &leg4)
: leg1(leg1),leg2(leg2),leg3(leg3),leg4(leg4){

    legs[0] = &leg1;
    legs[1] = &leg2;
    legs[2] = &leg3;
    legs[3] = &leg4;
}

  void dog::home(){ 
    for (int i = 0; i< 4; i++){
      legs[i]->home();
      // Serial.println(i);
    }
  }


  void dog::move(float x, float y, float z){ 
    // for (int i = 0; i< 4; i++){
    // legs[i]->updatePosition(x,y,z);

    // // Serial.println(i);
    // }
  } 


  void dog::rpyControl(float y, float b, float a){
    //Roll - y // Pitch - b // Yaw - a

    y = y * PI/180;
    b = b * PI/180;
    a = a * PI/180;
    

    for (int i = 0; i < 1; i++){
    //Calculate Hip Transformation
      float x_hip_rotated = legs[i]->d_cent_hip[0] * (cos(a) * cos(b)) - legs[i]->d_cent_hip[1] * (sin(b)) + legs[i]->d_cent_hip[2] * (cos(b) * sin(a));
      float y_hip_rotated = legs[i]->d_cent_hip[0] * (sin(a)*sin(y) + cos(a)*sin(b)*cos(y)) - legs[i]->d_cent_hip[2] * (cos(a)*sin(y) - sin(a)*sin(b)*cos(y)) + legs[i]->d_cent_hip[1] * (cos(b) * cos(y));
      float z_hip_rotated = legs[i]->d_cent_hip[2] * (cos(a)*cos(y) + sin(a) * sin(b) * sin(y)) - legs[i]->d_cent_hip[0] * (sin(a) * cos(y) - cos(a) * sin(b) * sin(y)) + legs[i]->d_cent_hip[1] * (cos(b) * sin(y));

      Serial.print(x_hip_rotated);
      Serial.print("    ");
      Serial.print(y_hip_rotated);
      Serial.print("    ");
      Serial.print(z_hip_rotated);
      Serial.println("    ");

      // Serial.print(legs[i]->d_cent_foot[0]);
      // Serial.print("    ");
      // Serial.print(legs[i]->d_cent_foot[1]);
      // Serial.print("    ");
      // Serial.print(legs[i]->d_cent_foot[2]);
      // Serial.println("    ");

      float x_hip_foot = legs[i]->d_cent_foot[0] - x_hip_rotated; 
      float y_hip_foot = -(legs[i]->d_cent_foot[1] - y_hip_rotated);
      float z_hip_foot = legs[i]->d_cent_foot[2] - z_hip_rotated;

      // Serial.print(x_hip_foot);
      // Serial.print("    ");
      // Serial.print(y_hip_foot);
      // Serial.print("    ");
      // Serial.print(z_hip_foot);
      // Serial.println("    ");

      // Serial.print("Leg");
      // Serial.print("  ");
      // Serial.print(i);
      // Serial.print("  ");
      // Serial.print("calculated");
      // Serial.println("  ");

      legs[i]->IK(x_hip_foot, y_hip_foot, z_hip_foot);

    }
  }
