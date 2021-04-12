int pompom = A2;               // name of the first sensor key
int touchValue; 

void setup() {
  // put your setup code here, to run once:

  pinMode(pompom, INPUT);   // set key1 to be an input
  Serial.begin(9600); 
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
    touchValue = readCapacitivePin(pompom); // read the touch sensor value
    Serial.println(touchValue);           // send touchValue to the computer
  1delay(100);

}
