int pompom = 3;               // name of the first sensor key
int touchValue; 
int led= 0;
int ledIntensity;

/*#include <SoftwareSerial.h>

const byte txPin = 1;
const byte txPin = 3;

SoftwareSerial mySerial (rxPin, txPin);*/

void setup() {
  // put your setup code here, to run once:

  pinMode(pompom, INPUT);   // set key1 to be an input
  pinMode(led, INPUT);
  //Serial.begin(9600); 
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
    touchValue = readCapacitivePin(pompom); // read the touch sensor value
    //Serial.println(touchValue);           // send touchValue to the computer
    delay(100);

    ledIntensity= map(touchValue,1,12,0,255); 
    analogWrite(led, ledIntensity);
    
    

}
