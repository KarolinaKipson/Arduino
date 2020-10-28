/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// include core Wiring API
#include "Arduino.h"

// include this library's description file
#include "My_DCMotor.h"

// include description files for other libraries used (if any)
//#include "HardwareSerial.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

My_DCMotor::My_DCMotor(int pin1, int pin2, int speed)
{
  

  // do whatever is required to initialize the library
     pinMode(pin1,OUTPUT);                                                  // this will create an instance of DC_Motor
     pinMode(pin2,OUTPUT);	 // in the arduino sketch with motor driver pins
	 pinMode(speed,OUTPUT);
	 
     digitalWrite(pin1,LOW);
     digitalWrite(pin2,LOW);
	 analogWrite(speed, 0);
	 
	 // initialize this instance's variables
     pin_1 = pin1;
     pin_2 = pin2;
	 motor_speed = speed;
     
}

void My_DCMotor::forward_full_speed(void){
	
	 digitalWrite(pin_1,HIGH);
     digitalWrite(pin_2,LOW);
	 analogWrite(motor_speed, 255);
	 
}
void My_DCMotor::forward_with_speed(int speed){
	
	if(speed > 255 || speed < 0){
		digitalWrite(pin_1,LOW);
        digitalWrite(pin_2,LOW);
		analogWrite(motor_speed, 0);
	} else {
		digitalWrite(pin_1,HIGH);
        digitalWrite(pin_2,LOW);
	    analogWrite(motor_speed, speed);
	}
	
	 
}

void My_DCMotor::reverse_full_speed(void){
	
	 digitalWrite(pin_1,LOW);
     digitalWrite(pin_2,HIGH);
	 analogWrite(motor_speed, 255);
	 
}
void My_DCMotor::reverse_with_speed(int speed){
	
	if(speed > 255 || speed < 0){
		digitalWrite(pin_1,LOW);
        digitalWrite(pin_2,LOW);
		analogWrite(motor_speed, 0);
	} else {
	 digitalWrite(pin_1,LOW);
     digitalWrite(pin_2,HIGH);
	 analogWrite(motor_speed, speed);
	 }
	 
}

void My_DCMotor::dc_break()                        
  {
      digitalWrite(pin_1,HIGH);
      digitalWrite(pin_2,HIGH);  
      analogWrite(motor_speed, 0);	  
  } 
////////////////////////////////// // this function will stop the motor //////////////////////////////////////////////  
void My_DCMotor::stop_motor()                        
  {
      digitalWrite(pin_1,LOW);
      digitalWrite(pin_2,LOW); 
      analogWrite(motor_speed, 0);	  
  } 


