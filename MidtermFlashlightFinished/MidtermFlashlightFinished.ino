//This is a modified version of Adafruit's basic beginners tutorials on a FSR, Servo Motor, and Potentiometer 

#include <Servo.h>

int val;

int fsrAnalogPin = A1; 
int fsrReading; 
int LEDdim;

int LED1 = 11;
int LED2 = 10;
int LED3 = 9;
int LED4 = 6;
int LED5 = 5;

Servo myservo;

void setup(){

  Serial.begin(9600);
  myservo.attach(3); 
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
   pinMode(LED4, OUTPUT);
   pinMode(LED5, OUTPUT);

}

void loop(){

  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);

///DIMNESS

 LEDdim = map(fsrReading, 0, 1023, 0, 255);
 analogWrite(LED1, LEDdim);

 LEDdim = map(fsrReading, 0, 1023, 0, 255);
 analogWrite(LED2, LEDdim);

  LEDdim = map(fsrReading, 0, 1023, 0, 255);
 analogWrite(LED3, LEDdim);

  LEDdim = map(fsrReading, 0, 1023, 0, 255);
 analogWrite(LED4, LEDdim);

  LEDdim = map(fsrReading, 0, 1023, 0, 255);
 analogWrite(LED5, LEDdim);



  
///POTENTIOMETER
  val = analogRead(A0); //potentiometer 
  val= map(val, 0, 1024, 0 , 180); // map in 0 t0 180
  myservo.write(val);
  Serial.println(val);
 
}
