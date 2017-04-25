/*************************
Joel Bartlett
SparkFun Electronics
December 27, 2012

This code controls a stepper motor with the 
EasyDriver board. It spins forwards and backwards
***************************/
/////STEPPER MOTOR BY ITSELF


int dirpin = 2;
int steppin = 3;

int sensorPin = A0;    
int sensorValue = 0;


void setup(){
  Serial.begin(9600);
  
  pinMode(dirpin, OUTPUT);
  pinMode(steppin, OUTPUT);
            }

void loop(){
////motor direction
  int i;
  digitalWrite(dirpin, LOW);   
  delay(100);

    sensorValue = analogRead(sensorPin);
  delay(500);
  Serial.println(sensorValue);

  
 if (sensorValue > 400){   
  for (i = 0; i<10000; i++){
  // Iterate for 4000 microsteps. 
    digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steppin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
    delayMicroseconds(150);      // This delay time is close to top speed for this
      }   
      }
      else {
      digitalWrite(steppin, LOW);
      }
      }

      
 
