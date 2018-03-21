String command;
String string;
boolean ledon = false;
//#define led 5
int ledpin= 8;
void setup()
{
Serial.begin(9600);
pinMode(ledpin, OUTPUT);
}
void loop()
{
/*if (Serial.available() > 0)
{string = '1';}*/
while(Serial.available() > 0)
{
Serial.println("riddhi");  
command = (Serial.readString());     // TAKES INPUT FROM SERIAL, THE STRING THAT WE HAVE PASSED.
if(command == ":")
{
break;
}
else
{
string = command;
Serial.println(string);
}
delay(1);
}
if(string == "O")  
{
ledOn();
ledon = true;
}
if(string == "F")
{
ledOff();
ledon = false;
Serial.println(string); //debug
}
/*if ((string.toInt()>=0)&&(string.toInt()<=255))
{
if (ledon==true)
{
//analogWrite(led, string.toInt());
int  val = analogRead(Serial.available());   // read the input pin
  analogWrite(ledpin, val / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255

Serial.println(string); //debug
delay(10);
}
}*/
}
void ledOn()
{
analogWrite(ledpin, 255);
delay(10);
}
void ledOff()
{
analogWrite(ledpin, 0);
delay(10);
}
