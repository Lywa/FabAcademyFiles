//www.elegoo.com
//2016.06.13


// TAP MODULE SKETCH controlling LED time with a delay.
int Led=13;//define LED port
int buttonpin=3; //define switch port
;int  val;//define digital variable val
void  setup()
{
pinMode(Led,OUTPUT);//define LED as a output port
pinMode(buttonpin,INPUT);//define switch as a output port
}
void  loop()

{ val=digitalRead(buttonpin);//read the value of the digital interface 3 assigned to val 
if(val==HIGH)//when the switch sensor have signal, LED blink
{
digitalWrite(Led,HIGH);
delay(1000);
}
else
{
digitalWrite(Led,LOW);
}
}


