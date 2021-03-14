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

bool OnOff = false;
int val = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(0, OUTPUT);
  pinMode(2, INPUT);
}

// the loop function runs over and over again forever
void loop() {

  val = digitalRead(2);   // read the input pin
  //digitalWrite(0, val); 
  
 if (val == HIGH){
  digitalWrite(0 , LOW);    // turn the LED off by making the voltage LOW

  }else if ( val ==LOW){
  
       
     for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
  
      // sets the value (range from 0 to 255):
  
      analogWrite(0, fadeValue);
  
      // wait for 30 milliseconds to see the dimming effect
  
      delay(30);
  
    }
  
    // fade out from max to min in increments of 5 points:
  
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
  
      // sets the value (range from 0 to 255):
  
      analogWrite(0, fadeValue);
  
      // wait for 30 milliseconds to see the dimming effect
  
      delay(30);

  }
  }


}
