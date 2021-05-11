#define RED 3  // check
#define GREEN 5 // check
#define BLUE 6

#define off 255
#define on 0

#include <Servo.h> 

Servo myServo;
String letters;
//char letters[1];

/* This RGBLed is driven using PWM outputs.
    as my RGB LED is common Anode(+), led is driven "reversed":
    higher PWM value means dimmer light.
    lower PWM value means brigher light.
    PWM Value set to 0 means "Color full on"
    PWM Value set to 255 means "Color full off"
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

  myServo.attach(12);
  myServo.write(180);
  
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  analogWrite(RED, off);
  analogWrite(GREEN, off);
  analogWrite(BLUE, off);

}

int rValue = on;
int gValue = on;
int bValue = on;

void loop() {

  if (Serial.available()) {
    byte rcvd = Serial.read();
    char rcvdAr[1];
    sprintf(rcvdAr, "%c", rcvd);
    letters = String(rcvdAr);

    Serial.print(letters);
    Serial.println("ack");
  }

  if (letters == "A") {

    analogWrite(RED, on);
    analogWrite(GREEN, off);
    analogWrite(BLUE, off);
    myServo.write(180);

  } else if (letters=="T") {

    analogWrite(RED, off);
    analogWrite(GREEN, on);
    analogWrite(BLUE, off);
    myServo.write(45);

  } else if (letters == "C" ) {

    analogWrite(RED, off);
    analogWrite(GREEN, off);
    analogWrite(BLUE, on);
    myServo.write(90);

  } else if (letters == "G" ) {

    analogWrite(RED, on);
    analogWrite(GREEN, on);
    analogWrite(BLUE, on);
    myServo.write(135);

  }

}
