//This is a modified version of last semester's homework assignment in Coding for Artists.

import processing.serial.*;

Ball[] b = new Ball[450];
Serial myPort;

float Value;

int i;

float radius = 75;
float angle = 0;
float theta = 0;
float x = 0.1;

void setup(){
  size(1270,800);
  background(0);

  
  for (int i = 0; i < b.length; i++){
    b[i] = new Ball(random(width), random(height), random(-0.1, 0.1), random(-0.1, 0.1), random(20,100), random(20,100));
}

  myPort = new Serial(this, Serial.list()[2], 9600);

  myPort.bufferUntil('\n');
}

void draw(){
  
  
  for(int i=0; i<b.length; i++){
  b[i].display();
}
}

void serialEvent(Serial myPort) {
  String inString = myPort.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);
   Value = float(inString);
     Value = map(Value,0, 180, 0, 255);
    println(Value);
  }
}
