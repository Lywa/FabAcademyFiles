/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
 #define outputA 16
 #define outputB 13

 int counter = 0; 
 int aState;
 int aLastState; 

  #include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

 void setup() { 

   myservo.attach(10);  // attaches the servo on pin 5 to the servo object
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
 } 

 void loop() { 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state

   if (counter==0){ 
     myservo.write(85);              // tell servo to go to position in variable 'pos'

    
   }else if (counter ==10){
   
    myservo.write(95);              // tell servo to go to position in variable 'pos'
  
   }
 }
