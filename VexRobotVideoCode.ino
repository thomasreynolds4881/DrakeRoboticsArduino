//************************** vexMotorRobotControl *****************************************
// Created By: Thomas Reynolds, Luke Gentle, using code from Evan Weinberg
// 
// Created On: 2/14/2020
//
// Last Modified: 2/14/2020
//
// Purpose: 
//
//*****************************************************************************************


#include <Servo.h>


const int leftMotorPin = 5;       //Left motor pin
const int LEDPin = 13;            //LED pin

Servo leftMotor;                  //Define variables for each motor

void setup() 
{
  // put your setup code here, to run once:
  pinMode(leftMotorPin,OUTPUT);   //Set leftMotorPin to be an output pin.
  pinMode(LEDPin,OUTPUT);         //Set LEDPin to be an output pin.
  
  leftMotor.attach(leftMotorPin); //leftMotor will be controlled by leftMotorPin

}//End of setup

// put your main code here, to run repeatedly:
void loop() 
{
  //Send full forward to both motors
  motorControl(leftMotor, 100);
  digitalWrite(LEDPin,HIGH);      //Turn the LEDpin on
  delay(1000);                    //Wait 1000 ms, or one second

  
  motorControl(leftMotor, -100);  //Send full backward to both motors
  digitalWrite(LEDPin,LOW);       //Turn the LEDpin off
  delay(1000);
  
}//End of loop


//The functions below let you send a power value between -100 and 100 to the motors. 
//The servo library uses numbers between 1000 and 2000 to control servos. 
int motorControl(Servo motor, int value)
{
  motor.write(map(value,-100,100,1000,2000));
}//End of motorControl
