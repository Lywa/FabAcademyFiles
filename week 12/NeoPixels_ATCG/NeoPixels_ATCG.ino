// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        12 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 10 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

int color = 1;

const int buttonPin = 4;     // the number of the pushbutton pin

int buttonState = 0;  

String input;

int led= 1;

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  pixels.setBrightness(10);

   // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  Serial.begin(9600); 

  Serial.println("Type A, C, T or G");



}

void loop() {


  if(Serial.available()){
        input = Serial.readStringUntil('\n');
        Serial.println(input);
        led++;
    }
   
  //pixels.clear(); // Set all pixel colors to 'off'

  /*pixels.setPixelColor(8, pixels.Color(0, 0, 250));
  
  pixels.setPixelColor(9, pixels.Color(250, 0, 0));

  pixels.setPixelColor(6, pixels.Color(0, 255, 0));
  
  pixels.setPixelColor(7, pixels.Color(255, 255, 255));*/

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.

  
 /* for(int i=0; i<(NUMPIXELS); i++) { // For each pixel...

  buttonState = digitalRead(buttonPin);
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    //pixels.setPixelColor(i, pixels.Color(70, 0, 250));

    

     if (buttonState == LOW) {
      //change color
      color ++;
       pixels.clear();
       i=0;
     } else {
     
     }

    selectColor(i, (color%4)+1);

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }*/

  if( input == "A"){

    color = 1;
    
  }else if( input == "T"){

    color = 2;

    
  }else if( input == "C"){
    
   color = 3;

  }else if( input == "G"){
    
   color = 4;

  }


    selectColor((led%10)+1, (color%4)+1);

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
 
    

  
}

void selectColor(int i, int color){
  
  if ( color == 1 ){

     pixels.setPixelColor(i, pixels.Color(250, 250, 250));
    
  }else if ( color == 2){

     pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    
  } else if ( color == 3){

     pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    
  }else if ( color == 4){

     pixels.setPixelColor(i, pixels.Color(0, 0, 250));
    
  }else{
    
  }
}
