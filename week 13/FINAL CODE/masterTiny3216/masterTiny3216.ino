#include <Wire.h>
#define I2C_INIOFFSET 8
#define LED 6

void setup() {
  // put your setup code here, to run once:

  Wire.begin();
#if (defined(__AVR_ATtiny1614__) || defined(__AVR_ATtiny1616__) || defined(__AVR_ATtiny1617__) || defined(__AVR_ATtiny3216__) || defined(__AVR_ATtiny3217__) )
  Wire.swap(1);
#endif
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

}

char deviceList[] = {'C', 'A', 'T', 'G'};  // save the status of each secondary
int currentDevice = 0;


void loop() {
 
  // do things!!!!
  //digitalWrite(LED, ledState); // Debugging LED

    Wire.beginTransmission(I2C_INIOFFSET + currentDevice);
    Wire.write(deviceList[currentDevice]);
    Wire.endTransmission();

    char serMsg[40];
    sprintf(serMsg, "Sent '%c' to address '%d'.", deviceList[currentDevice], I2C_INIOFFSET + currentDevice );
    Serial.println(serMsg);

    currentDevice++;
    currentDevice = currentDevice % sizeof(deviceList);
    
  delay(500); //i2c requires ~80ns per byte sent.addr+byte=~160ns.
  // if the receiver is very slow, 1ms may not be enough.
}
