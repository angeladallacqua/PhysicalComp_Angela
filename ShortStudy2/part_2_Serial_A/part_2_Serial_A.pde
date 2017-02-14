Ball[] b = new Ball[80];

int i;
float radius = 75;
float angle = 0;
float theta = 0;
float x = 0.1;

//////////////////////////

import processing.serial.*; //imports Serial library from Processing

Serial myPort; // creates object from Serial class
int val; // creates variable for data coming from serial port

//////////////////////////

void setup(){
 size(600,600);
  background(255);

printArray(Serial.list()); // this line prints the port list to the console
String portName = Serial.list()[1]; //change the number in the [] for the port you need
myPort = new Serial(this, portName, 9600);


  for (int i = 0; i < b.length; i++){
    b[i] = new Ball(random(width), random(height), random(-0.1, 0.1), random(-0.1, 0.1), random(20,100), random(20,100));
}
}


void draw(){
  
  if ( myPort.available() > 0) { // If data is available,
val = myPort.read(); // read it and store it in val
}

//////////
  
  
  
  for(int i=0; i<b.length; i++){
  b[i].display();
}

println (val); //prints to Processing console
}