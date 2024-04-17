#include "botcontrol.h"
#include "main.h"
#include "robot-config.h"
using namespace vex;

  // if (fabs(input)<width){
  //   return(0);
  // }
  // return(input);
int pxpos = 480/2;
int pypos = 240/2;
int turningCurve = 5;
int x = 1;
int push = 0;
int y = 1;
int push1 = 0;
bool turningRed = false;

int forwardCurve = 10;
bool forwardRed = false;

int curveJoystick(bool red, int input, double t){
  int val = 0;
  if(red){
    val = (std::exp(-t/10)+std::exp((std::abs(input)-100)/10)*(1-std::exp(-t/10))) * input;
  }else{
    //blue
    val = std::exp(((std::abs(input)-100)*t)/1000) * input;
  }
  return val;
}

void driver(){
  while(1){
    // double turnVal = curveJoystick(false, con.Axis1.position(percent), turningCurve); //Get curvature according to settings [-100,100]
    // double forwardVal = curveJoystick(false, con.Axis3.position(percent), forwardCurve); //Get curvature according to settings [-100,100]

    // double turnVolts = turnVal * 0.12; //Converts to voltage
    // double forwardVolts = forwardVal * 0.12; //Converts to voltage

    // leftmo.spin(forward, forwardVolts + turnVolts, voltageUnits::volt); //Apply Via Voltage
    // rightmo.spin(forward, forwardVolts - turnVolts, voltageUnits::volt);

    // vex::task::sleep(20);
    if(con.ButtonR1.pressing()){
      inta.spin(reverse, 100, pct);
    } else if(con.ButtonR2.pressing()){
      inta.spin(fwd, 100, pct);
    } else{
      inta.stop(hold);
    }

      //elevation button need to change
    if(con.ButtonL2.pressing() == true)
      {
        x++;
      }
    else
      {
        x = 0 ;
      }
    if(x == 1)
      {
        if(push == 0)
        {
          elevation.set(true);
          push = 1;
        }
        else if (push == 1)
        {
          
          elevation.set(false);
          
          push = 0;
        }
      }
    //wing
    if(con.ButtonL1.pressing() == true)
      {
        y++;
      }
    else
      {
        y = 0 ;
      }
    if(y == 1)
      {
        if(push1 == 0)
        {
          intawings.set(true);
          push1 = 1;
        }
        else if (push1 == 1)
        {
          intawings.set(false);
          push1 = 0;
        }
      }

/////////////////////////////////////////////////////////////////

    double axis3 = con.Axis3.position(pct);
    double axis1 = -con.Axis1.position(pct);
    double leftVolt = axis3 - axis1;
    double rightVolt = axis3 + axis1;
    double scale = 12.0 / fmax(12.0, fmax(fabs(leftVolt), fabs(rightVolt)));
    leftVolt *= scale;
    rightVolt *= scale;
    if (fabs(leftVolt) < 0.1){
        leftmo.stop(brake);
    } 
    else{
        leftmo.spin(forward, leftVolt, volt);
    }
    if(fabs(rightVolt) < 0.1){
        rightmo.stop(brake);
    }
    else{
        rightmo.spin(forward, rightVolt, volt);
    }

//////////////////////////////////////////////////////////////////////////////


    wait(20, msec);
  }
}