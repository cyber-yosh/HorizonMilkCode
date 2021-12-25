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
// LeftDriveMotor2      motor         18              
// RightDriveMotor1     motor         15              
// RightDriveMotor2     motor         16              
// intakeMotor          motor         10              
// LobsterBot           motor         4               
// pClamp               digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;



bool reversedrive=false;
bool intakereverse=false;
bool lobsterset=false;
bool intaketoggle=false;

void reversedir() {
  if (reversedrive==false){
    reversedrive=true;
  } 
  else {
    reversedrive=false;
  }
}

void lobsterGoal() {
  if (lobsterset=true) {
    LobsterBot.spinToPosition(315, deg);
    lobsterset=false;
  }
  else {
    LobsterBot.spinToPosition(0, deg);
    lobsterset=true;
  }
}


void reversein() {
  if (intakereverse==false){
    intakereverse=true;
  } 
  else {
    intakereverse=false;
  }
}

void clamp(){
  if (pClamp.value()==true){
    pClamp.set(false);
  }
  else {
    pClamp.set(true);
  }
}

void intakeonoff() {
  if (intaketoggle==false){
    intaketoggle=true;
  } 
  else {
    intaketoggle=false;
  }
}

//these revolution values need to be altered, please CHANGE THEM TO BE THE RIGHT VALUE, it will be easier and more precise in the long run.
void dummyLobster(){
  LobsterBot.spinFor(directionType::rev, 50, rev);
}

void dummyLobster2(){
  LobsterBot.spinFor(directionType::fwd, 50, rev);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();



  while (true){
    Controller1.ButtonA.pressed(reversedir);
    Controller1.ButtonX.pressed(reversein);
    Controller1.ButtonY.pressed(clamp);
    Controller1.ButtonB.pressed(intakeonoff);


    if (intaketoggle==true){

      if (intakereverse==false){
        intake.spin(directionType::fwd, 100.0, velocityUnits::pct);
      }

      if (intakereverse==true) {
        intake.spin(directionType::rev, 100.0, velocityUnits::pct);
      }
    }
    
    fourbar.spin(directionType::rev, (Controller1.Axis2.value()), velocityUnits::pct);
    fourbar2.spin(directionType::fwd, (Controller1.Axis2.value()), velocityUnits::pct);

    if (reversedrive==false){
      LeftDriveMotor1.spin(directionType::rev, (Controller1.Axis3.value() - Controller1.Axis4.value()), velocityUnits::pct);
      LeftDriveMotor2.spin(directionType::rev, (Controller1.Axis3.value() - Controller1.Axis4.value()), velocityUnits::pct);
      RightDriveMotor1.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value()), velocityUnits::pct);      
      RightDriveMotor2.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value()), velocityUnits::pct);
    }
    if (reversedrive==true){
      LeftDriveMotor1.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value()), velocityUnits::pct);
      LeftDriveMotor2.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value()), velocityUnits::pct);
      RightDriveMotor1.spin(directionType::rev, (Controller1.Axis3.value() + Controller1.Axis4.value()), velocityUnits::pct);      
      RightDriveMotor2.spin(directionType::rev, (Controller1.Axis3.value() + Controller1.Axis4.value()), velocityUnits::pct);
    }
    Controller1.ButtonR2.pressed(dummyLobster);
    Controller1.ButtonR1.pressed(dummyLobster2); 
    Controller1.ButtonL1.pressed(lobstergoal);
  }
}
  

