//Modification of Adafruit VS1053
//Modification of SparkFun Example Code for Stepper Motor 
//Modification of Adafruit IR Sensor example code

#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6 

#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3   

boolean randommusic;
int StepOne;
int StepTwo;

Adafruit_VS1053_FilePlayer musicPlayer = 
  // create shield-example object!
Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

////////////////////////////////////////////////////STEPPER MOTOR
 
int dirpin = 2;
int steppin = 9;


////////////////////////////////////////////////////IR SENSOR

int sensorPin = A0;
int sensorValue = 0;

void setup(){
  Serial.begin(9600);
  
  pinMode(dirpin, OUTPUT);
  pinMode(steppin, OUTPUT);


////////////////////////////////////////////////////
   Serial.println("Adafruit VS1053 Simple Test");
   if (! musicPlayer.begin()) { // initialise the music player
   Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
   while (1);
                              }
   Serial.println(F("VS1053 found"));
   if (!SD.begin(CARDCS)) {
   Serial.println(F("SD failed, or not present"));
   while (1);  // don't do anything more
                          }
// Set volume for left, right channels. lower numbers == louder volume!
   musicPlayer.setVolume(1,20);
           }
           

void loop(){

//////////////////////////////////////////////////////STEPPER MOTOR

 int i;
  digitalWrite(dirpin, LOW);   
  delay(100);
  
//////////////////////////////////////////////////////IR sensor

 sensorValue = analogRead(sensorPin);
 delay(500);
 Serial.println(sensorValue);

 ///////////////////////////////////HEAD SPINNING


       if (sensorValue > 450){   
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

////////////////////////////////////////////////////MUSICMAKER

if (musicPlayer.stopped()) {
Serial.println("music stopped");

//////////////////////////////////SECOND STEP
 if (sensorValue > 200 && sensorValue < 399){   
  StepTwo = int(random(5,7));

if (StepTwo == 5){
   Serial.println(F("Playing track 005"));
   musicPlayer.playFullFile("track005.mp3");
   Serial.write(StepTwo);
}

if (StepTwo == 6){
  Serial.println(F("Playing track 006"));
  musicPlayer.playFullFile("track006.mp3");
  Serial.write(StepTwo);
}

 }

/////////////////////////////////////////////////////FIRST STEP

 if (sensorValue > 95 && sensorValue < 149){   
  StepOne = int(random(2,4));

if (StepOne == 2){
   Serial.println(F("Playing track 002"));
   musicPlayer.playFullFile("track002.mp3");
   Serial.write(StepOne);
}

if (StepOne == 3){
  Serial.println(F("Playing track 003"));
  musicPlayer.playFullFile("track003.mp3");
  Serial.write(StepOne);
}
 }

/////////////////////////////////////////////////////GETTING YOUR ATTENTION

 if (sensorValue < 55){   
   Serial.println(F("Playing track 001"));
   musicPlayer.playFullFile("track001.mp3");
}
}
  
      }
