// Constants.cpp
#include "parameters.h"

// Dimensions
// Leg Parameters
const float l1 = 110;
const float l2 = 120;
const float d1 = 42.827;

// Torso Parameters
const float L1 = 123.03;
const float L2 = 95.15;
const float h = 11.26;
const float w = 50.36;

// Default Torso -> Foot Positions
const float xf1 = 104.3;
const float xf2 = 95.32;
const float yf = 200.36;
const float zf = 93.19;

// Reflection Maps for Joints
int leg1_map[6] = {0,0,1,1,1,1};
int leg2_map[6] = {1,1,0,1,-1,1};
int leg3_map[6] = {1,0,1,1,1,1};
int leg4_map[6] = {0,1,0,1,-1,1};

// Distance from Centoid to Hip Frame: 
float d_hip1[3] = {L1, h, w};
float d_hip2[3] = {L1, h, -w};
float d_hip3[3] = {-L2, h, w};
float d_hip4[3] = {-L2, h, w};

// Distance from Centroid to Foot at Rest Pose
float d_foot1[3] = {xf1, -yf, zf};
float d_foot2[3] = {xf1, -yf, -zf};
float d_foot3[3] = {-xf2, -yf, zf};
float d_foot4[3] = {-xf2, -yf, -zf};

// Home Position For General Case Leg
float home_position[3] = {0, 161.285, 42.827};
char incomingByte = 0;
