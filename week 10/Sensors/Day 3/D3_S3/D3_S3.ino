#include <IRremote.h>
IRsend irsend;

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
 Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop() 
{

  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
   for (int i = 0; i < 50; i++) { 
     irsend.sendSony(0xa90, 12); // Sony TV power code
     Serial.println("sending");
     delay(40);
   }
  
  delay(100);
}




