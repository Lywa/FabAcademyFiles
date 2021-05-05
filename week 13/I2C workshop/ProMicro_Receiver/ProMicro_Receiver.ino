#include <Wire.h>

void setup() {
    Wire.begin();        // join i2c bus (address optional for master)
    Serial.begin(9600);  // start serial for output
     pinMode(LED_BUILTIN, OUTPUT);
    
}

void loop() {
    Wire.requestFrom(8, 2);    // request 6 bytes from slave device #8

    while (Wire.available()) { // slave may send less than requested
        char c = Wire.read();    // receive a byte as character
        Serial.print(c);
        // print the character

    if (c == 'H'){
    
     digitalWrite(LED_BUILTIN, HIGH); 
     delay(100);
    Serial.print("hey");
    } else if (c == 'L') {

     digitalWrite(LED_BUILTIN, LOW); 
       Serial.print("horay");
     delay(100);
      
    }else{
    }
     
    }

    //delay(500);
} 
