#include <Wire.h>

void setup() {
    Wire.begin(8);                // join i2c bus with address #8
    Wire.onRequest(requestEvent); // register event
}

void loop() {
    delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
    Wire.write("H"); // respond with message of 6 bytes
    Serial.print("H");

    delay(100);
    Wire.write("L");
    Serial.print("L");
    delay(100);
    // as expected by master
}
