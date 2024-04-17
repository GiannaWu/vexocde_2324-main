#include "main.h"
#include "utility/buttons.h"
#include "robot-config.h"


int autonpick() {
    while(1){
  if (Brain.Screen.pressing()){
    int X = Brain.Screen.xPosition();
    int Y = Brain.Screen.xPosition();
    if ((Y >= 120)){
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(0,0,480,272);
      Brain.Screen.setFillColor(red);
      Brain.Screen.printAt(180,136, "Close Auton");
      return 2;
    } else if(Y <= 120){
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(0,0,480,272);
      Brain.Screen.setFillColor(red);
      Brain.Screen.printAt(190,136, "Far Auton");
      return 1;
    }
  }
}
}