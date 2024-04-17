#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller con;
motor l1 = motor(PORT1, ratio6_1, 1);
motor l2 = motor(PORT2, ratio6_1, 1);
motor l3 = motor(PORT3, ratio6_1, 1);
motor_group leftmo = motor_group(l1, l2, l3);
motor r1 = motor(PORT11, ratio6_1, 0);
motor r2 = motor(PORT12, ratio6_1, 0);
motor r3 = motor(PORT13, ratio6_1, 0);
motor_group rightmo = motor_group(r1, r2, r3);
inertial bob = inertial(PORT15);
motor inta = motor(PORT7, ratio18_1, 0);
motor pner = motor(PORT4, ratio18_1, 0);
digital_out intawings = digital_out(Brain.ThreeWirePort.D);
digital_out elevation = digital_out(Brain.ThreeWirePort.A);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}