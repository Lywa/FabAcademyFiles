// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
String msg;
int id;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8 (0x08). can go up to #119 included (0x77)
#if (defined(__AVR_ATtiny1614__) || defined(__AVR_ATtiny1616__) || defined(__AVR_ATtiny1617__) || defined(__AVR_ATtiny3216__) || defined(__AVR_ATtiny3217__) )
  Wire.swap(1);
#endif
  Wire.onReceive(receiveEvent); // register event
  //Serial.begin(115200);           // start serial for output
  pinMode(4, OUTPUT);

}

void loop() {
  //delay(100);  // should use avdweb_VirtualDelay instead for better management.
  if (msg != "") {
    //Serial.println(msg);
    msg = "";
  }
  if (id % 10)
    digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  else
    digitalWrite(4, LOW);   // turn the LED on (HIGH is the voltage level)

}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  msg = "";
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    msg += c;
  }
  int x = Wire.read();    // receive last byte as an integer
  id = x;
  msg += x;
}
