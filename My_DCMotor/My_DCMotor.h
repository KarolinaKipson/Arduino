/*
  My_DCMotor_h - Library for controlling a motor based on Test.h.
  Copyright (c) 2020 Karolina Kipson.  All right reserved.
*/

// ensure this library description is only included once
#ifndef My_DCMotor_h
#define My_DCMotor_h

// include types & constants of Wiring core API
#include "Arduino.h"

// library interface description
class My_DCMotor
{
  // user-accessible "public" interface
  public:
    My_DCMotor(int pin1,int pin2, int pwr);
    void forward_full_speed(void);
    void forward_with_speed(int speed);
    void reverse_full_speed(void);
    void reverse_with_speed(int speed);
    void stop_motor(void);
    void dc_break(void);  

  // library-accessible "private" interface
  private:
            int pin_1,pin_2,motor_speed;
};

#endif

