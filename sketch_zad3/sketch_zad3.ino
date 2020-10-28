
// number 8 5x with led blinking
#include <My_DCMotor.h>

My_DCMotor dcmotor1(3, 2, 8);
My_DCMotor dcmotor2(4, 5, 9);

 unsigned long startDriveMillis;
 unsigned long currentMillis;
 unsigned long startPeriod = 0;
 unsigned long drivePeriod1 = 1300;
 unsigned long drivePeriod2 = 5500;
 unsigned long changePeriod = 9500;
 int loopCount = 0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(LED_BUILTIN, OUTPUT);
 digitalWrite(LED_BUILTIN, LOW);
 startDriveMillis = millis(); 
}

void loop() {
  // put your main code here, to run repeatedly:   
  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  long difference = currentMillis- startDriveMillis;
   Serial.println(difference);
   
  if(difference >= changePeriod){   
     startDriveMillis = currentMillis;
     loopCount++;
     if(loopCount <= 5){
       blinkLed(loopCount);  
      } 
  }
  else if (difference >= drivePeriod2 && difference  < changePeriod)  //test whether the period has elapsed
  {      
     dcmotor1.forward_with_speed(130);
     dcmotor2.forward_with_speed(250);  
     //Serial.println(3);   
  } 
 else if(difference >= drivePeriod1 && difference < drivePeriod2) {
     dcmotor1.forward_with_speed(245);
     dcmotor2.forward_with_speed(130);      
     // Serial.println(2);         
    }
 else if(difference >= startPeriod && difference < drivePeriod1) {    
        dcmotor1.forward_with_speed(130);
        dcmotor2.forward_with_speed(250);     
     //Serial.println(1);    
    }
   if(loopCount >= 5){
    dcmotor1.stop_motor();
    dcmotor2.stop_motor();
    }
}

void blinkLed(int number){
   for(int i = 1; i<= number;i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(150);
    digitalWrite(LED_BUILTIN, LOW);
    delay(150);
    }
  }
