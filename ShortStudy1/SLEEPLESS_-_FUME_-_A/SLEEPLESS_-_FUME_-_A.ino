int LED1 = 13; 
int LED2 = 12; 
int LED3 = 11; 
int LED4 = 10; 
int LED5 = 9; 
int LED6 = 8; 
int LED7 = 6;
const int BUTTON = 7; 
int val = 0;
int fadeValue;
int fadeValue2;

void setup() {

Serial.begin(9600);
  
pinMode(LED1, OUTPUT); 
pinMode(LED2, OUTPUT); 
pinMode(LED3, OUTPUT); 
pinMode(LED4, OUTPUT); 
pinMode(LED5, OUTPUT); 
pinMode(LED6, OUTPUT); 
}

void loop(){
 

   

           for(int fadeValue=0; fadeValue <=100; fadeValue += 5){

                   analogWrite(LED3, fadeValue);
                 Serial.println(fadeValue);
                 delay(30);
            }

            
           for(int fadeValue=0; fadeValue <=100; fadeValue += 5){

                   analogWrite(LED4, fadeValue);
                 Serial.println(fadeValue);
                 delay(30);
            }

               for(int fadeValue=0; fadeValue <=100; fadeValue += 5){

                   analogWrite(LED5, fadeValue);
                 Serial.println(fadeValue);
                 delay(30);
            }
            
////////////////////////////////////////////////////////////////////////

            
  val = digitalRead(BUTTON); 

if (val == HIGH) {
digitalWrite(LED1, LOW); 

}
else{ digitalWrite(LED1, HIGH);
} 


////////


if (val == HIGH) {
digitalWrite(LED2, HIGH); 

}
else{ digitalWrite(LED2, LOW);
} 


/////////


if (val == HIGH) {
digitalWrite(LED1, HIGH); 

}
else{ digitalWrite(LED1, LOW);
} 


//////////

if (val == HIGH) {
digitalWrite(LED6, HIGH); 



}
else{ digitalWrite(LED6, LOW);
} 
///////////////////////////////////////////////////////////////////////

if (val == HIGH){
digitalWrite(LED7, LOW);
delay(90);
  digitalWrite(LED7, HIGH);
}
            


}
