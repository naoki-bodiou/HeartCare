#include "param.h"
void setup() 
{
  
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);


}

void loop() 
{


  if (MODE == 1) //Toutes les LEDS sont allumées en même temps
{
for(int i=12;i>=3;i--) 
{
  digitalWrite(i, HIGH);
  
}
}
if (MODE == 2) //1 LED sur 2 est allumée
{
int i = 12;
while (i>=3) 
{
  digitalWrite(i, HIGH);
  i = i - 2;
}


}
if (MODE == 3) //1 LED sur 3 est allumée
{
int i = 12;
while (i>=3) 
{
  digitalWrite(i, HIGH);
  i = i - 3;
}

}
if (MODE == 4) //Coeur en mode "chenille"
{
for (int i = 3; i < 13; i++) 
{
  digitalWrite(i, HIGH);
  delay(1000);
  digitalWrite(i, LOW);
}
}
}
