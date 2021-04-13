// 7 color flash LED SKETCH

int Led = 13;
 
void setup ()
{
  pinMode (Led, OUTPUT); // Initialize LED
}
 
void loop () 
{
  digitalWrite (Led, HIGH); // LED ON
  delay (4000); // Wait 4 seconds
  digitalWrite (Led, LOW); // LED OFF
  delay (2000); // Wait 2 seconds
}
