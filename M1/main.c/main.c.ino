
#include "cardio.h"

void setup() 
{
Serial.begin(9600);
}

void loop() 
{
  TestPoul(); //lancement de la fonction TestPoul
  delay(random(200,300));  
}
