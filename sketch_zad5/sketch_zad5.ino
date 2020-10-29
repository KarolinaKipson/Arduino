
// echolocation in practice
#include <My_DCMotor.h>

My_DCMotor dcmotor1(3, 2, 8);
My_DCMotor dcmotor2(4, 5, 9);
int trigPin1 = 43;      // trig pin
int echoPin1 = 45;     // Echo pin 
int trigPin2 = 40;      // trig pin
int echoPin2 = 44;     // Echo pin 
bool isStopped;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin1, OUTPUT);         // set trig pin as output
pinMode(echoPin1, INPUT);          //set echo pin as input to capture reflected waves
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT); 
isStopped = false;
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration1, duration2, distance1, distance2;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);// send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH); // receive reflected waves
  distance1 = (duration1 /2)/29.1;   // convert to distance
  //Serial.println(distance1);
 
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);  
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH); 
  distance2 = (duration2 /2)/29.1;
 // Serial.println(distance2);
    Serial.println(isStopped);
    
  if(distance2 > 40 && isStopped == false ){
     dcmotor1.forward_with_speed(245);
     dcmotor2.forward_with_speed(255); 
     Serial.println("forward"); 
    } 
   if(distance2 < 40  && isStopped == false) {     
           dcmotor1.forward_with_speed(210);
           dcmotor2.forward_with_speed(0); 
           delay(1500);
           dcmotor1.reverse_with_speed(240);
           dcmotor2.reverse_with_speed(240);  
           delay(900); 
            dcmotor1.stop_motor();
            dcmotor2.stop_motor();        
           isStopped = true;        
      }
}
