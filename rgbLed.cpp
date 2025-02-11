#include "Arduino.h"
#include "rgbLed.h"

RGBLed::RGBLed()
{
  // Setting up rgbLed pins as output
  for(int i = 9; i < 12; i++) pinMode(i, OUTPUT);
}//constructor

void RGBLed::randomiseColourSequence (int &level)
{
  int arrayMembersLeft = 7;
  int i = 0;
  
  for(int j = 0; j < 7; j++)  ledRGBColoursIndices[j] = 0;// for loop to set elements of ledRGBColoursIndices array to 0
  int arrayOfIndices [7] = {0, 1, 2, 3, 4, 5, 6};
  populateledRGBColoursIndices(arrayMembersLeft,  (arrayMembersLeft - 7), arrayOfIndices, i, 0, 7);
}// randomise colour seqeunce


void RGBLed::populateledRGBColoursIndices(int &arrayMembersLeft, int numberOfMembersLeftAfterInsert, int arrayPins[], int &i, int minRandNumber, int maxRandNumber)
{
  randomSeed(analogRead(A5));
  int randomIndex = random(minRandNumber, maxRandNumber);
  while(arrayMembersLeft > numberOfMembersLeftAfterInsert)
  {// place pin numbers in random positions of ledSequenceArray
      if(ledRGBColoursIndices[randomIndex] == 0)
      {
        ledRGBColoursIndices[randomIndex] = arrayPins[i];
        i++;
        arrayMembersLeft--;
      }
   randomIndex = random(minRandNumber, maxRandNumber);
  }

}//populate ledSequenceArray

void RGBLed::lightRGBLed(int &level)
{
  if(level == 1)
  {// level 1 
  
    for (int  i = 0; i < 2; i++)
    {// for loop to light RGB LED (using first 2 elements of ledRGBColoursIndices)in 2 colours of colourRGBValues array (that was randomised)
      analogWrite(RED_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][0]);//RED
      analogWrite(GREEN_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][1]);//GREEN
      analogWrite(BLUE_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][2]);//BLUE
      delay(3000);
    }
  }//level 1

    if(level == 2)
  {// level 2 
    for (int  i = 0; i < 4; i++)
    {// for loop to light RGB LED (using first 4 elements of ledRGBColoursIndices) in 4 colours of colourRGBValues array (that was randomised)
      analogWrite(RED_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][0]);//RED
      analogWrite(GREEN_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][1]);//GREEN
      analogWrite(BLUE_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][2]);//BLUE
      delay(3000);
    };
  }//level 2

    if(level == 3)
  {// level 3
    for (int  i = 0; i < 6; i++)
    {// for loop to light RGB LED (using first 6 elements of ledRGBColoursIndices) in 6 colours of colourRGBValues array (that was randomised)
      analogWrite(RED_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][0]);//RED
      analogWrite(GREEN_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][1]);//GREEN
      analogWrite(BLUE_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][2]);//BLUE
      delay(2000);
    }
  }//level 3

    if(level == 4)
  {// level 4
    for (int  i = 0; i < 7; i++)
    {// for loop to light RGB LED (using the elements of ledRGBColoursIndices) in 7 colours of colourRGBValues array (that was randomised)
      analogWrite(RED_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][0]);//RED
      analogWrite(GREEN_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][1]);//GREEN
      analogWrite(BLUE_RGB_PIN, colourRGBValues[ledRGBColoursIndices[i]][2]);//BLUE
      delay(2000);
    }
  }//level 4

    analogWrite(RED_RGB_PIN, 0);
    analogWrite(GREEN_RGB_PIN, 0);
    analogWrite(BLUE_RGB_PIN, 0);

}//lightRGBLed