#include <My_DCMotor.h>

// Doing Something
// by Karolina Kipson 

// Demostrates how to use My_DCMotor library

// Created 3 October 2020

My_DCMotor dcmotor1(2, 3, 8);
My_DCMotor dcmotor2(4, 5, 9);

void setup()
{
}

void loop()
{
  dcmotor1.forward_full_speed();
  dcmotor2.forward_full_speed();
  delay(1000);
  dcmotor1.stop_motor();
  dcmotor2.stop_motor();
  delay(1000);
  dcmotor1.reverse_full_speed();
  dcmotor2.reverse_full_speed();
  delay(1000);
  dcmotor1.stop_motor();
  dcmotor2.stop_motor();
  delay(1000);
  dcmotor1.forward_with_speed(160);
  dcmotor2.forward_with_speed(160);
  delay(1000);
  dcmotor1.stop_motor();
  dcmotor2.stop_motor();
  delay(1000);
  dcmotor1.reverse_with_speed(160);
  dcmotor2.reverse_with_speed(160);
  delay(1000);
  dcmotor1.stop_motor();
  dcmotor2.stop_motor();
  delay(1000);
}

