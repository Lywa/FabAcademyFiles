#include <Servo.h>
#include <Wire.h>

#define LED 4
#define SERIAL_ENABLED 0
char msg = 0;

bool ledSt = false;
int servoPos = 12;
Servo myServo;

void setup() {
  // put your setup code here, to run once:

  Wire.begin(11);                // join i2c bus with address #8 (0x08). can go up to #119 included (0x77)
#if (defined(__AVR_ATtiny1614__) || defined(__AVR_ATtiny1616__) || defined(__AVR_ATtiny1617__) || defined(__AVR_ATtiny3216__) || defined(__AVR_ATtiny3217__) )
  Wire.swap(1);
#endif
#if SERIAL_ENABLED
  Serial.begin(115200);
#endif
  Wire.onReceive(receiveEvent); // register event

  myServo.attach(1);

  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (msg == 'A') {
    servoPos = 45;
  }
  else if (msg == 'C') {
    servoPos = 90;
  }
  else if (msg == 'G')
    servoPos = 135;
  else if (msg == 'T')
    servoPos = 180;
  //else

  myServo.write(servoPos);
  digitalWrite(LED, ledSt);
  digitalWrite(LED_BUILTIN, ledSt);
  delay(10);
}


// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    msg = c;
  }
  ledSt = !ledSt;
#if SERIAL_ENABLED
  Serial.println(msg);
#endif

}
