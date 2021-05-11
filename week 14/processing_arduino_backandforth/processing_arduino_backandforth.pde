
import processing.serial.*;

import cc.arduino.*;

// The serial port:
Serial myPort;


String[] letters = { "A","T","C","G","B","N"};

void setup() {
  size(720, 480);
  
 
  
  // List all the available serial ports:
  printArray(Serial.list());

// Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[4], 9600);

  
}

void draw() {
  
   if(0< myPort.available()){
     println(myPort.readString());
  }
 
  for( int i=0; i<letters.length; i++){

   println(letters[i]);
   myPort.write(letters[i]);

  }
 
  
 
}
