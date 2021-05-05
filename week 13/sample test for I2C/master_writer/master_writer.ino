// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
#if (defined(__AVR_ATtiny1614__) || defined(__AVR_ATtiny1616__) || defined(__AVR_ATtiny1617__) || defined(__AVR_ATtiny3216__) || defined(__AVR_ATtiny3217__) )
  Wire.swap(1);
#endif
}

byte x = 0;

void loop() {
  int targetDevice = 8;  // transmit to device #8
  Wire.beginTransmission(targetDevice); 
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte. number is sent as byte, not as strings.
  Wire.endTransmission();    // stop transmitting
 /// message sent is "x is ITERATION_NUMBER"
  x++;
  x = x % 256;  // 256 is max value for a byte datatype. 
  delay(x);  // should use avdweb_VirtualDelay instead for better management. 
}
