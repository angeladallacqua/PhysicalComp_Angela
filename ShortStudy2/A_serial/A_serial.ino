int sensorPin = 0; //sensor hooked up to analog pin 0
int val = 0;

void setup() {
Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
val = analogRead(sensorPin); //read sensor and assign to variable called val
delay(100); // Wait 100 milliseconds
Serial.write(val);
//Serial.read(val);
}
