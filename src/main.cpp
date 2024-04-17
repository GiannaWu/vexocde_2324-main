#include "vex.h"
#include "botcontrol.h"
#include "basic_control.h"
#include "robot-config.h"
#include "main.h"
#include "autons/auton.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;
competition Competition;

int originX = 0;
int width = 240;
  
bool intawing = 0;
      
// int conlef = con.Axis1.position()+con.Axis3.position();

int endX = originX + width;

int autonoption = 0;
    float deadband(float input, float width){
  if (fabs(input)<width){
    return(0);
  }
  return(input);
}

void pre_auton(void) {
  vexcodeInit();
  bob.startCalibration();
  while(bob.isCalibrating()){
    wait(10, msec);
  }
  heading_convert(bob.heading());
  while(1){
  if (Brain.Screen.pressing()){
    int X = Brain.Screen.xPosition();
    int Y = Brain.Screen.xPosition();
    if ((Y >= 120)){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(red);
      Brain.Screen.printAt(180,136, "Close Auton");
      autonoption = 1;

    } else if(Y <= 120){
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(0,0,480,272);
      Brain.Screen.setFillColor(red);
      Brain.Screen.printAt(190,136, "Far Auton");
      autonoption = 2;
    }
  }
    wait(20, msec);

  }
}

void autonomous(void) {
close_qua();
// test();
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(red);
  Brain.Screen.printAt(((480/2)-36), (240/2), "Auton Start!");
  // if(autonoption == 2){
  //   far();
  // } else if(autonoption == 1){

  // }
}

void usercontrol(void) {
  driver();

}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}