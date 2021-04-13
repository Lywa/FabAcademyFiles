//Sketch PIR controlling DC motor

int motorPin = 3;

int ledPin = 13;                // choose the pin for the LED
int inputPin = 7;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;
int speed =100;
int stop = 0;
 
void setup() 
{ 

  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
  Serial.println("But the advice 50 to 255. Because the minimum voltage required to start the motor is 50.");
} 
 
 
void loop() 
{ 
  
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!, speed 100");
      // We only want to print on the output change, not state
      pirState = HIGH;
      analogWrite(motorPin, speed);
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!, speed 0");
      // We only want to print on the output change, not state
      pirState = LOW;
      analogWrite(motorPin, stop);
    }
  }
 
} 
