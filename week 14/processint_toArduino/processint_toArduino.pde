
import processing.serial.*;

import cc.arduino.*;

// The serial port:
Serial myPort;


PImage img;

/*
color off = color(4, 79, 111);
color on = color(84, 145, 158);*/

String[] letters = { "A","T","C","G","B","N"};

void setup() {
  size(720, 480);
  
  img = loadImage("Inteface_ATCG_S.png");
  background(img);
  
  
  // List all the available serial ports:
  printArray(Serial.list());

// Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[4], 9600);

  
}

void draw() {
 
  
  if(0< myPort.available()){
     println(myPort.readString());
  }
/*for( int i=0; i<letters.length; i++){

  print( letters[i]);

}*/
 
  
 
}

void mousePressed()
{
 
  if( mouseX > 50 && mouseX< 170){
  
   println(letters[0]);
   myPort.write(letters[0]);

  } else if ( mouseX > 205 && mouseX< 350){
  
   println(letters[1]);
   myPort.write(letters[1]);
  
  } else if ( mouseX > 375 && mouseX< 505){
  
   println(letters[2]);
    myPort.write(letters[2]);
   
  } else if ( mouseX > 535 && mouseX< 675){
  
   println(letters[3]);
   myPort.write(letters[3]);
   
  }
}
