//************************** vexMotorRobotControlFull *****************************************
// Created By: Thomas Reynolds, Luke Gentle, Khe Kit Shum using code from Evan Weinberg
// 
// Created On: 2/14/2020
//
// Last Modified: 2/21/2020
//
// Purpose: Control Vex motors
//
//*****************************************************************************************

#include <Servo.h>

#define MOTORL 9
#define MOTORR 10
#define JOY 0

Servo motorL,motorR;              //Define variables for each motor set
int joyX = 0;
int joyVal;

void setup() 
{
  pinMode(MOTORL,OUTPUT);   //Set MOTOR1 to be an output pin.
  pinMode(MOTORR,OUTPUT);
  
  motorL.attach(MOTORL); //motorL will be controlled by MOTORL pin
  motorR.attach(MOTORR);

  Serial.begin(9600);

}//End of setup


void loop() 
{
  joyVal = analogRead(joyX);
  Serial.print(joyVal);
  Serial.print("\n");
  if (joyVal < 500 || joyVal > 540){
    Serial.print((joyVal-520)/12); //This works but I don't know why
    Serial.print("\n");
    motorControl((joyVal-520)/12);
  }else{
    motorControl(0);
  }
  delay(10);                    //Wait 10 ms to check again
  
}//End of loop


//The functions below let you send a power value between -100 and 100 to the motors. 
//The servo library uses numbers between 1000 and 2000 to control servos.
int motorControl(int value)
{
  motorL.write(map(value,-100,100,1000,2000));
  motorR.write(map(value,-100,100,1000,2000));
}//End of motorControl
