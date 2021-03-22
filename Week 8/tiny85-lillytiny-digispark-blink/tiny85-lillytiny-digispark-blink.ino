/*
add this board library url
http://digistump.com/package_digistump_index.json
from the board manager, Install
Digistump AVR Boards

Close arduino IDE;
open a terminal
run the following commands:

cd ~/Library/Arduino15/packages/arduino/tools/avr-gcc
mv 4.8.1-arduino5 orig.4.8.1
ln -s /Applications/Arduino.app/Contents/Java/hardware/tools/avr 4.8.1-arduino5

The above commands replace the avr-gcc compiler that comes with the board manager 
 libraries with the embedded into Arduino IDE, 
 which has everything you need to program this board.
 This info came from: https://digistump.com/board/index.php/topic,3198.msg14379.html#msg14379 

Open Arduino IDE again and load your code.

To program the board:
Select board: "Digistump AVR Boards' >> ""Digispark (default - 16.5Mhz"
Select Programmer "Micronucleus"

Click Upload with the board UNPLUGGED
Plug the board when you are asked to do so.
*/

/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
