#include "Arduino.h"
#include "levelLeds.h"

LevelLeds::LevelLeds()
{
  //Set level indicator leds to output
   for(int i = 14; i < 18; i++) pinMode(i, OUTPUT);
}

void LevelLeds::beginLevel()
{
  // All LEDs are lit to indicate a level will begin.
   for(int i = 0; i < 4; i++)
   {
      digitalWrite(LevelLedsPins[level - 1], HIGH);
      delay(500);
      digitalWrite(LevelLedsPins[level - 1], LOW);
      delay(500);
   }
   delay(2000);// wait 2 seconds before starting level
   digitalWrite(LevelLedsPins[level - 1], HIGH);
}//beginLevel


void LevelLeds::completedLevel()
{
   for(int i = 0; i < 4; i++) digitalWrite(LevelLedsPins[i], LOW);
   delay(2000);

   for(int i = 0; i < 4; i++)
   {
      for(int j = 0 ; j < 3; j++){
      digitalWrite(LevelLedsPins[i], HIGH);
      delay(500);
      }
   }

   for(int i = 0; i < 4; i++)
   {
      for(int j = 0 ; j < 3; j++){
      digitalWrite(LevelLedsPins[i], LOW);
      delay(500);
      }
   }

   delay(2000);// wait 2 seconds before starting level
   for(int i = 0; i < level ; i++) digitalWrite(LevelLedsPins[i], HIGH);
   delay(1000);// wait 1 second before starting level
}//completedLevel


void LevelLeds::gameFinished()
{
   Serial.println("Congratulations!!! YOU WIN!");
   for(int i = 0; i < 4; i++) digitalWrite(LevelLedsPins[i], LOW);
   
   while(1)
   {
     for(int i = 0; i < 4; i++)
      {
       for(int j = 0 ; j < 3; j++){
       digitalWrite(LevelLedsPins[i], HIGH);
       delay(500);
      }
     }

    for(int i = 0; i < 4; i++)
     {
      for(int j = 0 ; j < 3; j++){
      digitalWrite(LevelLedsPins[i], LOW);
      delay(500);
      }
    }
   }
}//gameFinished

void LevelLeds::gameOver()
{
   Serial.println("GAME OVER :(");
   while(1)
   {
      for(int i = 0; i < 4; i++) digitalWrite(LevelLedsPins[i], HIGH);
      delay(500);
      for(int i = 0; i < 4; i++) digitalWrite(LevelLedsPins[i], LOW);
      delay(500);
   }
}//gameOver