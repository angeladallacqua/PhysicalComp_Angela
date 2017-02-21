#include <Servo.h>

int val;

Servo myservo;

void setup(){

  Serial.begin(9600);
  myservo.attach(3); // assign servo on pin 9
}

void loop(){

  val = analogRead(A0); // read potentiometer 
  val= map(val, 0, 1024, 0 , 180); // map in 0 t0 180
  myservo.write(val);  //sends values to my servo
  //delay(100);
}
