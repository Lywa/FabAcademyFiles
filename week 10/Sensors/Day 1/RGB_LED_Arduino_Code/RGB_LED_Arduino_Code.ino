// Output
int redPin   = 9;   // Red LED,   connected to digital pin 9
int greenPin = 10;  // Green LED, connected to digital pin 10
int bluePin  = 11;  // Blue LED,  connected to digital pin 11

int redPinEvil   = 5;   // Red LED,   connected to digital pin 9
int greenPinEvil = 6;  // Green LED, connected to digital pin 10
int bluePinEvil  = 7;  // Blue LED,  connected to digital pin 11

long int inByte; 
int wait = 10; //10ms

void setup()
{
  pinMode(redPin,   OUTPUT);   // sets the pins as output
  pinMode(greenPin, OUTPUT);   
  pinMode(bluePin,  OUTPUT);
   pinMode(redPinEvil,   OUTPUT);   // sets the pins as output
  pinMode(greenPinEvil, OUTPUT);   
  pinMode(bluePinEvil,  OUTPUT);
  
  Serial.begin(9600); 
}


void outputColour(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green); 
  analogWrite(redPinEvil, red);
  analogWrite(bluePinEvil, blue);
  analogWrite(greenPinEvil, green); 
  delay(3000); 
  analogWrite(redPinEvil, 255);
  analogWrite(bluePinEvil, 255);
  analogWrite(greenPinEvil, 255); 
  delay(100);
  analogWrite(redPinEvil, red);
  analogWrite(bluePinEvil, blue);
  analogWrite(greenPinEvil, green);
  delay(100);
  analogWrite(redPinEvil, (random(1,1000000)%255));
  analogWrite(bluePinEvil, (random(1,1000000)%255));
  analogWrite(greenPinEvil, (random(1,1000000)%255));    
}


int* getColour() {
  int* colour;
  int i;
  
  i = 0;
  
  //for some reason it only works if we put a dud value between the C and 
  // the R value
  while (i < 4)
  {
    if (Serial.available() > 0) {
        colour[i] = Serial.read();
        i++;
    }
  }
  
  return colour;
}

// Main program
void loop()
{
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    
     if (inByte == 'C') {
        int* one;
      one =  getColour();
      
      //1 2 3 not 0 1 2 due to the dud value
      outputColour(one[1],one[2],one[3]);
       
       
    } 
  }
  
  delay(wait);
 
}
