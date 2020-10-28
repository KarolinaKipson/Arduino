// spin 5x in one direction and 5x in another
#include <My_DCMotor.h>

My_DCMotor dcmotor1(3, 2, 8);
My_DCMotor dcmotor2(4, 5, 9);

 unsigned long startDriveMillis;
 unsigned long currentMillis;
 const unsigned long drivePeriod1 = 0;
 const unsigned long turnPeriod1 = 1000; 
 const unsigned long drivePeriod2 = 11400;
 const unsigned long turnPeriod2 = 12400; 
 const unsigned long drivePeriod3 = 23400;
 const unsigned long stopPeriod = 24000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  startDriveMillis = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
   long difference = currentMillis- startDriveMillis;
 

  if (difference == drivePeriod1 && difference < turnPeriod1 )  //test whether the period has elapsed
  {      
     dcmotor1.forward_with_speed(245);
     dcmotor2.forward_with_speed(255);     
  }
  if(difference == turnPeriod1){
     dcmotor1.forward_with_speed(252);
     dcmotor2.forward_with_speed(50);  
    }
  if (difference == drivePeriod2 && difference < turnPeriod2 )  //test whether the period has elapsed
  {      
     dcmotor1.forward_with_speed(245);
     dcmotor2.forward_with_speed(255);     
  }
  if(difference == turnPeriod2) {
     dcmotor1.forward_with_speed(50);
     dcmotor2.forward_with_speed(252);      
    }
  if (difference == drivePeriod3)  //test whether the period has elapsed
  {      
     dcmotor1.forward_with_speed(245);
     dcmotor2.forward_with_speed(255);     
  }
    if(difference == stopPeriod){   
    // startDriveMillis = currentMillis; 
     dcmotor1.stop_motor();
     dcmotor2.stop_motor();   
  }
}
