/*************************
Joel Bartlett
SparkFun Electronics
December 27, 2012

This code controls a stepper motor with the 
EasyDriver board. It spins forwards and backwards
***************************/
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
int steppin = 3;


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
  
//////////////////////////////////////////////////////IR sensor

 sensorValue = analogRead(sensorPin);
 delay(500);
 Serial.println(sensorValue);

////////////////////////////////////////////////////MUSICMAKER

if (musicPlayer.stopped()) {
Serial.println("music stopped");

/////////////////////////////////////////////////////GETTING YOUR ATTENTION

 if (sensorValue < 40){   
   Serial.println(F("Playing track 001"));
   musicPlayer.playFullFile("track001.mp3");
}

/////////////////////////////////////////////////////FIRST STEP

 if (sensorValue > 400){   
  StepOne = int(random(2,5));

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

if (StepOne == 4){
   Serial.println(F("Playing track 004"));
   musicPlayer.playFullFile("track004.mp3");
   Serial.write(StepOne);
        }
        }

//////////////////////////////////SECOND STEP
 if (sensorValue > 100){   
  StepTwo = int(random(5,8));

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

if (StepTwo == 7){
   Serial.println(F("Playing track 007"));
   musicPlayer.playFullFile("track007.mp3");
   Serial.write(StepTwo);
        }
        }
        }

///////////////////////////////////HEAD SPINNING

        
           
        }
