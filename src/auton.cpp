#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;

void close_qua(){
timer timerer;
timerer.reset();
setHeading(0);
// vex::pneumatics intawings = vex::pneumatics(Brain.ThreeWirePort.D);
// wait(1,msec);

// intawings.set(true);
// pner.spin(fwd,100,pct);
sped = 0.1;
driveAndTurn(2.3, 90, 80, 100);
sped = 0.06;
driveAndTurn(-1, 0, 100, 70);
intawings.set(1);
driveAndTurn(0.4, -20, 100, 100);
pner.spin(fwd, 100, pct);
wait(1, sec);
pner.stop(coast);
intawings.set(0);
turnToAngle(30);
driveAndTurn(-4.76, 0, 90, 100, 3500);
driveAndTurn(-1.7, -90, 80, 100);
turnToAngle(0);



// inta.spin(fwd,100,pct);

// // turnToAngle(90);
// driveAndTurn(3, 46,100,100);
// intawings.set(false);
// // driveAndTurn(0.5,46,70,70);
// driveAndTurn(-2.7, -36,100,100,1400);
// inta.spin(reverse,70,pct);
// turnToAngle(130,100,950);
// inta.spin(fwd,90,pct);
// turnToAngle(-56,100,900);
// driveAndTurn(1.7,-48,100,100);
// driveAndTurn(-1,-48);
// turnToAngle(135,100);
// //intawings.set(true);
// inta.spin(reverse,100,pct);
// driveAndTurn(1.2, 62,73,80);
// turnToAngle(45);
// //intawings.set(false);

// turnToAngle(-90);

// driveAndTurn(-2,-195,100,100,1000);
// sped = 1;
// driveAndTurn(7,-45);
// intawings.set(true);
// l1.stop(coast);
// l2.stop(coast);
// l3.stop(coast);
// r1.stop(coast);
// r2.stop(coast);
// r3.stop(coast);



// intawings.set(true);
// driveAndTurn(-2,-120);

// intawings.set(false);
// driveAndTurn(-0.5,-120);
// driveAndTurn(2,-130);
// driveAndTurn(-1,-130);
// driveAndTurn(1,-130);




// //driveAndTurn(-1.5, 0);
// driveAndTurn(0.4, 40);
// driveAndTurn(-0.6, 40);
// driveAndTurn(1.5, 0);
// intawings.open();
// wait(1, msec);
// turnToAngle(100);
// driveAndTurn(0.3, 0);
// driveAndTurn(-0.6, 0);

//turnToAngle(90);
//suk(100);
//unsuk(100);
}