// IR sensors to control movement, follow black line
#include <My_DCMotor.h>

My_DCMotor dcmotor1(3, 2, 8);
My_DCMotor dcmotor2(4, 5, 9);

// positions from right to left, while robot facing forward
const int IR_pin1= 31;
const int IR_pin2= 33;
const int IR_pin3= 35;
const int IR_pin4= 37;
const int IR_pin5= 39;

int inputVal1 = 0;
int inputVal2 = 0;
int inputVal3 = 0;
int inputVal4 = 0;
int inputVal5 = 0;

void setup() {
  // put your setup code here, to run once:
 pinMode(IR_pin1,INPUT); 
 pinMode(IR_pin2,INPUT);  
 pinMode(IR_pin3,INPUT);  
 pinMode(IR_pin4,INPUT);  
 pinMode(IR_pin5,INPUT);  
 Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
inputVal1 = digitalRead(IR_pin1);
inputVal2 = digitalRead(IR_pin2);
inputVal3 = digitalRead(IR_pin3);
inputVal4 = digitalRead(IR_pin4);
inputVal5 = digitalRead(IR_pin5);
Serial.println(inputVal1);

if(inputVal3 == LOW && inputVal1 == HIGH && inputVal5 == HIGH && inputVal2 == HIGH){
    dcmotor1.forward_with_speed(195);
    dcmotor2.forward_with_speed(210);
   // Serial.println(3);
  }   
 else if(inputVal3 == HIGH && (inputVal1 == LOW && inputVal5 == HIGH)){
   dcmotor1.forward_with_speed(200);
   dcmotor2.forward_with_speed(0);
    // Serial.println(1);
    }
  //inputVal2 too sensitive
else if(inputVal3 == HIGH && (inputVal2 == LOW && inputVal5 == HIGH)) {
    // excluded pin1 because IR sensor is too sensitive  
     dcmotor1.forward_with_speed(200);
      dcmotor2.forward_with_speed(0);
    // Serial.println(2);
    }
     
 //excluded pin4 because IR sensor on position 4 always reads high
   else if(inputVal3 == HIGH && inputVal5 == LOW && inputVal2 == HIGH){
          dcmotor1.forward_with_speed(0);
          dcmotor2.forward_with_speed(200);
        // Serial.println(5);      
     } 
 else if(inputVal3 == HIGH && inputVal5 == LOW && inputVal2 == HIGH){
            dcmotor1.forward_with_speed(0);
          dcmotor2.forward_with_speed(200);
        // Serial.println(5);          
     } 

  else if(inputVal3 == LOW && inputVal5 == LOW && inputVal2 == LOW && inputVal1 == LOW){
           dcmotor1.stop_motor();
            dcmotor2.stop_motor();
        // Serial.println(0);      
     } 
       else if(inputVal3 == HIGH && inputVal5 == HIGH && inputVal2 == HIGH && inputVal1 == HIGH){
           dcmotor1.stop_motor();
            dcmotor2.stop_motor();
        // Serial.println(0);      
     } 
        
}
