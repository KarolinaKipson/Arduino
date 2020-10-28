//sinus line 
#include <My_DCMotor.h>

My_DCMotor dcmotor1(3, 2, 8);
My_DCMotor dcmotor2(4, 5, 9);

 unsigned long startDriveMillis;
 //unsigned long startTurnMillis;
 unsigned long currentMillis;
 const unsigned long drivePeriod1 = 0;
 const unsigned long turnPeriod1 = 1000; 
 const unsigned long drivePeriod2 = 2500;
 const unsigned long turnPeriod2 = 3500; 
 const unsigned long changePeriod = 4800;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  startDriveMillis = millis();  //initial start time
  //startTurnMillis = millis();
}

void loop() {
   currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
   long difference = currentMillis- startDriveMillis;
 
  if(difference > changePeriod){   
     startDriveMillis = currentMillis;   
  }
    else if (difference >= turnPeriod2 && difference < changePeriod)  //test whether the period has elapsed
  {      
     dcmotor1.forward_with_speed(210);
     dcmotor2.forward_with_speed(0);     
  }
   else if(difference >= drivePeriod2 && difference < turnPeriod2) {
     dcmotor1.forward_with_speed(250);
     dcmotor2.forward_full_speed();      
    } 
  else if(difference >= turnPeriod1 && difference < drivePeriod2) {
     dcmotor1.forward_with_speed(0);
     dcmotor2.forward_with_speed(180);      
    }
  else if(difference >= drivePeriod1) {
     dcmotor1.forward_with_speed(250);
     dcmotor2.forward_full_speed();      
    } 
    
 
}
