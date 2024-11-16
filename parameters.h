#ifndef PARAMETERS_H
#define PARAMETERS_H

// Dimensions
// Leg Parameters
extern const float l1;
extern const float l2;
extern const float d1;

// Torso Parameters
extern const float L1;
extern const float L2;
extern const float h;
extern const float w;

// Default Torso -> Foot Positions
extern const float xf1;
extern const float xf2;
extern const float yf;
extern const float zf;

// Reflection Maps for Joints
extern int leg1_map[6];
extern int leg2_map[6];
extern int leg3_map[6];
extern int leg4_map[6];

// Distance from Centoid to Hip Frame: 
extern float d_hip1[3];
extern float d_hip2[3];
extern float d_hip3[3];
extern float d_hip4[3];

// Distance from Centroid to Foot at Rest Pose
extern float d_foot1[3];
extern float d_foot2[3];
extern float d_foot3[3];
extern float d_foot4[3];

// Home Position For General Case Leg
extern float home_position[3];
extern char incomingByte;

#endif
