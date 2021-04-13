/*4x4 Matrix Keypad connected to Arduino
This code prints the key pressed on the keypad to the serial port*/

#include <Keypad.h>

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

int redpin = 11; // select the pin for the red LED
int greenpin = 10; // select the pin for the green LED
int val;

int counter= 0;

void setup()
{
pinMode (redpin, OUTPUT);
pinMode (greenpin, OUTPUT);
Serial.begin(9600);
Serial.println("Introduce the password starting by #");
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop()
  {
  char keypressed = myKeypad.getKey();

  analogWrite (greenpin, 0);
  analogWrite (redpin, 255);
  
  
  /*if (keypressed != NO_KEY)
  {
    Serial.print(keypressed);
  }*/
 
 
    
    if ((keypressed == '#')&&(counter==0))
    {
      Serial.print(keypressed);
      keypressed = myKeypad.getKey();
      counter=1;
      
       
        
      }else if ((keypressed == '2')&&(counter==1)){
        Serial.println(keypressed);
        analogWrite (greenpin, 255);
        analogWrite (redpin, 100);
        delay(1000);
        analogWrite (greenpin, 0);
        analogWrite (redpin, 255);
        delay(1000);
        analogWrite (greenpin, 255);
        analogWrite (redpin, 0);
        Serial.println("That's correct!");
        delay(5000);
        Serial.println("Introduce the password starting by #");
    }else if(keypressed != NO_KEY){

        Serial.println(keypressed);
        analogWrite (greenpin, 255);
        analogWrite (redpin, 100);
        delay(1000);
        analogWrite (greenpin, 0);
        analogWrite (redpin, 255);
        delay(1000);
        analogWrite (greenpin, 255);
        analogWrite (redpin, 100);
        delay(1000);
        analogWrite (greenpin, 0);
        analogWrite (redpin, 255);
        Serial.println("That's wrong!");
        delay(1000);
        counter = 0; 
        Serial.println("Introduce the password starting by #");
      
    }
  

}
