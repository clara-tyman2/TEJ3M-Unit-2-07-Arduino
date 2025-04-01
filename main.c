/*
* Created by: Clara T
* Created on: Apr 2025
* This program uses sonar amd servo
*/

#include <Servo.h>

Servo servoNumber1;

//constants
const int TRIG_PIN = 3;  
const int ECHO_PIN = 2; 
const int DISTANCE_THRESHOLD = 50;

//variables
float duration, distance_cm;

//setup
void setup() {  
   // setup servo pins
   servoNumber1.attach(5);
   servoNumber1.write(0);
  //pins for sonar
   pinMode(TRIG_PIN, OUTPUT);  
   pinMode(ECHO_PIN, INPUT); 
   Serial.begin(9600);  
}  


//loop
void loop() {  
  //clears the trig pin
  digitalWrite(TRIG_PIN, LOW);  
  delayMicroseconds(2);  

  //sets trig pin on high fpr 10 micro seconds
  digitalWrite(TRIG_PIN, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(TRIG_PIN, LOW);  

  //reads the echo pin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);  

  distance_cm = 0.017 * duration;
  
  if (distance_cm < DISTANCE_THRESHOLD){
  	servoNumber1.write(90);
  	delay(1000);
    servoNumber1.write(0);
    delay(500);
  }
}