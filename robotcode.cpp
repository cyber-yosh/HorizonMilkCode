/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       joshualuo                                                 */
/*    Created:      Fri Dec 24 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// fourbar              motor         7               
// fourbar2             motor         6               
// LeftDriveMotor1      motor         17              
// LobsterBot2          motor         12              
// RightDriveMotor1     motor         15              
// RightDriveMotor2     motor         16              
// intakeMotor          motor         10              
// LobsterBot           motor         11              
// pClamp               digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;



bool reversedrive=true;
bool intakereverse=false;
competition Competition;
bool lobsterset=false;
bool intakeon=false;
bool barCal = false;

void preAuton(){
  vexcodeInit();

}

void reversedir() {
  if (reversedrive==false){
    reversedrive=true;
  } 
  else {
    reversedrive=false;
  }
}

void intakeOnOff(){
  if (intakeon==false){ 
    intakeon=true;
  }
  else{
    intakeon=false;
  }
}

void lobsterDown() {
  if (lobsterset==false){
   LobsterBot.spinToPosition(-475, deg, false);  
   LobsterBot2.spinToPosition(-475, deg);
   LobsterBot.stop(brakeType::hold);
   LobsterBot2.stop(brakeType::hold);
   lobsterset=true;
 }
 else {
   LobsterBot.spinToPosition(-235, deg, false);  
   LobsterBot2.spinToPosition(-235, deg);
   LobsterBot2.stop(brakeType::hold);
   LobsterBot.stop(brakeType::hold);
   lobsterset=false;
 }
}



void reversein() {
  if (intakereverse==false){
       intakeMotor.setReversed(false);
     }
 
  else {
    intakeMotor.setReversed(true);
  }
}

void clampUp(){
  pClamp.set(true);
}

void clampDown(){
  pClamp.set(false);
}

void lobsterCal(){
  LobsterBot.spin(directionType::fwd, 100.0, velocityUnits::pct);
  LobsterBot2.spin(directionType::fwd, 100.0, velocityUnits::pct);
}
void lobsterStop() {
  LobsterBot.stop(brakeType::hold);
  LobsterBot2.stop(brakeType::hold);
}

void lobsterCal2(){
  LobsterBot.spin(directionType::rev, 100.0, velocityUnits::pct);
  LobsterBot2.spin(directionType::rev, 100.0, velocityUnits::pct);

}

void lobsterUpR(){
  
    LobsterBot.spinFor(directionType::fwd, 25, deg, false);
    LobsterBot2.spinFor(directionType::rev, 25, deg);
  }
void lobsterUpL() {
  LobsterBot.spinFor(directionType::rev, 25, deg, false);
  LobsterBot2.spinFor(directionType::fwd, 25, deg);
}

void fourbarCal(){
  fourbar.spinToPosition(-90, deg);
  fourbar2.spinToPosition(-90, deg);


}

void autonUp(){
  Controller1.Screen.print("Good Luck Jack");
  LeftDriveMotor1.setVelocity(100, velocityUnits::pct);
  RightDriveMotor1.setVelocity(100, velocityUnits::pct);
  intakeMotor.setVelocity(25, velocityUnits::pct);
  LobsterBot.setVelocity(100, velocityUnits::pct);
  LobsterBot2.setVelocity(100, velocityUnits::pct);
  fourbar.setVelocity(25, velocityUnits::pct);
  fourbar2.setVelocity(25, velocityUnits::pct);
  fourbar.setPosition(0, deg);
  fourbar2.setPosition(0, deg);

  LeftDriveMotor1.spinFor(directionType::fwd, 3.0, rev, false);
  RightDriveMotor1.spinFor(directionType::rev, 3.0, rev);
  fourbarCal();




  }



  void auton() {
    RightDriveMotor1.setVelocity(100.0, velocityUnits::pct);
    LeftDriveMotor1.setVelocity(100.0, velocityUnits::pct);
    fourbar.setVelocity(50.0, velocityUnits::pct);
    fourbar2.setVelocity(50.0, velocityUnits::pct);
    LobsterBot.setVelocity(50.0, velocityUnits::pct);
    LobsterBot2.setVelocity(50.0, velocityUnits::pct);
    intakeMotor.setVelocity(20.0, velocityUnits::pct);

    Controller1.Screen.print("Auton Started");

    fourbar.spinFor(directionType::fwd, 5.0, deg, false); //will need to be changed so that the l chanel goes to 2.04 inches
    fourbar.spinFor(directionType::fwd, 5.0, deg, false);
    LeftDriveMotor1.spinFor(directionType::rev, 27.815384598, deg, false); // value will need to change, diamter is not 4 
    RightDriveMotor1.spinFor(directionType::rev, 27.815384598, deg, true);
    RightDriveMotor1.spinFor(directionType::fwd, 9.69571428571, rev, false); //might need to change based on revolutions. might need to go like an inch further or maybe to go to 5.72777777778 revs
    LeftDriveMotor1.spinFor(directionType::rev, 9.69571428571, rev, true);
    clampDown();
    LeftDriveMotor1.spinFor(directionType::rev, 67.4, deg, false);
    RightDriveMotor1.spinFor(directionType::rev, 67.4, rev, true);
    RightDriveMotor1.spinFor(directionType::rev, 1.66296548246, rev, false); //might need to change based on revolutions
    LeftDriveMotor1.spinFor(directionType::fwd, 1.66296548246, rev, true);
    LeftDriveMotor1.spinFor(directionType::fwd, 90.0, deg, false);
    RightDriveMotor1.spinFor(directionType::fwd, 90.0, deg, true);
    RightDriveMotor1.spinFor(directionType::rev, 1.52165605096, rev, false); //might need to change based on revolutions
    LeftDriveMotor1.spinFor(directionType::fwd, 1.52165605096, rev, true);
    LeftDriveMotor1.spinFor(directionType::fwd, 77.4, deg, false);
    RightDriveMotor1.spinFor(directionType::fwd, 77.4, deg, true);
    lobsterDown();
    LeftDriveMotor1.spinFor(directionType::rev, 3.0134594732, rev, false); // might need to be a little further
    RightDriveMotor1.spinFor(directionType::fwd, 3.0134594732, rev, true);
    lobsterDown();
    intakeMotor.spinFor(directionType::fwd, 50.0, rev, true);
    Controller1.Screen.print("Auton Finished");


}




void driverControl() {
  // Initializing Robot Configuration. DO NOT REMOVE! vb



  while (1){
    
    
    if (intakeon==true){
      intakeMotor.spin(directionType::fwd, 50.0, velocityUnits::pct);
   } 
 
    else{
      intakeMotor.stop();
    }

    
    fourbar.spin(directionType::rev, (Controller1.Axis2.value())/2, velocityUnits::pct);

    fourbar2.spin(directionType::rev, (Controller1.Axis2.value())/2, velocityUnits::pct);
  
  

    if (reversedrive==false){
      LeftDriveMotor1.spin(directionType::rev, (Controller1.Axis3.value() - Controller1.Axis4.value()), velocityUnits::pct);
      RightDriveMotor1.spin(directionType::fwd,(Controller1.Axis3.value() + Controller1.Axis4.value()), velocityUnits::pct);      
    }
    else {                                                       
      LeftDriveMotor1.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value()), velocityUnits::pct);
      RightDriveMotor1.spin(directionType::rev,(Controller1.Axis3.value() - Controller1.Axis4.value()), velocityUnits::pct);      
    }
    Controller1.ButtonL1.pressed(lobsterDown);
    Controller1.ButtonX.pressed(reversein);
    Controller1.ButtonR1.pressed(clampDown);
    Controller1.ButtonRight.pressed(lobsterUpR);
    Controller1.ButtonLeft.pressed(lobsterUpL);
    Controller1.ButtonUp.pressed(lobsterCal);
    Controller1.ButtonDown.pressed(lobsterCal2);
    while (Controller1.ButtonR2.pressing()){
      fourbarCal();
    }

    Controller1.ButtonUp.released(lobsterStop);
    Controller1.ButtonDown.released(lobsterStop);
    Controller1.ButtonRight.released(lobsterStop);
    Controller1.ButtonLeft.released(lobsterStop);
    Controller1.ButtonR1.released(clampUp);
    Controller1.ButtonB.pressed(intakeOnOff);

    


  }
}
int main(){
  Competition.autonomous(autonUp);
  Competition.drivercontrol(driverControl);
  preAuton();

  while (true) {
    wait(100, msec);




  }
}
