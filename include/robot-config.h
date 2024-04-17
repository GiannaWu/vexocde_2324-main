#include "vex.h"
using namespace vex;

extern brain Brain;

// VEXcode devices
extern inertial bob;
extern controller con;
extern motor l1;
extern motor l2;
extern motor l3;
extern motor_group leftmo;
extern motor r1;
extern motor r2;
extern motor r3;
extern motor_group rightmo;
extern motor inta;
extern motor pner;
extern digital_out intawings;
extern digital_out elevation;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );