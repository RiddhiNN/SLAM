char command;
String string;
boolean ledon = false;
#define led 5
int ledpin= 5;
void setup()
{
Serial.begin(9600);
pinMode(ledpin, OUTPUT);
}
void loop()
{
if (Serial.available() > 0)
{string = "";}
while(Serial.available() > 0)
{command = ((byte)Serial.read());
if(command == ':')
{
break;
}
else
{
string += command;
}
delay(1);
}
if(string = "TO")
{
ledOn();
ledon = true;
}
if(string =="TF")
{
ledOff();
ledon = false;
Serial.println(string); //debug
}
if ((string.toInt()>=0)&&(string.toInt()<=255))
{
if (ledon==true)
{
//analogWrite(led, string.toInt());
int  val = analogRead(Serial.available());   // read the input pin
  analogWrite(ledpin, val / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255

Serial.println(string); //debug
delay(10);
}
}
}
void ledOn()
{
analogWrite(ledpin, 255);
delay(10);
}
void ledOff()
{
analogWrite(led, 0);
delay(10);
}
