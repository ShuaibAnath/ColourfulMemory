#include "Arduino.h"
#include "buttons.h"

Buttons::Buttons()
{
  // Setting up buttons as inputs
  for(int i = 2; i < 9; i++) pinMode(i, INPUT);
}// Button constructor

void Buttons::pollButtons(int &level, bool &gameOver)
{
bool  levelFinished = false;
while(isCorrectButtonPressed && !levelFinished)
{//while loop based on isCorrectButtonPressed state
 for(int i = 0; i < 7; i++)
 {// for loop to poll all 7 buttons
  int buttonRead = digitalRead(buttonPins[i]);
  
    if (buttonRead != lastButtonStates[i]) 
    {//begin debouncing
      lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceDelay) 
    {//Finish debouncing
      if (buttonRead != buttonStates[i]) 
      {
       buttonStates[i] = buttonRead;
        if (buttonRead == HIGH)
        { //if a button is pressed
          if(level == 1)
          {//level 1
            lightRGBLed(i, gameOver);
            if(numberOfCorrectButtonsPressed == 2)
            {
              levelFinished = true;
              numberOfCorrectButtonsPressed = 0;
              break;
            }
          }// level 1

          if(level == 2)
          {//level 2
            lightRGBLed(i, gameOver);
            if(numberOfCorrectButtonsPressed == 4)
            {
              levelFinished = true;
              numberOfCorrectButtonsPressed = 0;
              break;
            }
          }// level 2

          if(level == 3)
          {//level 3
            lightRGBLed(i, gameOver);
            if(numberOfCorrectButtonsPressed == 6)
            {
              levelFinished = true;
              numberOfCorrectButtonsPressed = 0;
              break;
            }
          }// level 3

          if(level == 4)
          {//level 4
            lightRGBLed(i, gameOver);
            if(numberOfCorrectButtonsPressed == 7)
            {
              levelFinished = true;
              numberOfCorrectButtonsPressed = 0;
              break;
            }
          }// level 4

        }// if buttonStates[i] is HIGH after debouncing

      }// if the state of the button that has been read differs from the current button state

    }// if debounce delay time has elapsed
  lastButtonStates[i] = buttonRead;// store button state read for next iteration of main loop
 
 }// for loop to poll all 7 buttons
 
}//while loop
delay(2000);// wait 2 seconds before writing low to RGB LED and next level starts 
}// pollButtons function

void Buttons::assignButtonPins(int* ledRGBColoursIndices)
{
   int temp = 0;
    for(int i = 0; i < 7; i++)
    {
      for(int j = 0; j < 8; j++ )
      {
        if(buttonPins[j] == (ledRGBColoursIndices[i] + 2))
        {
          //assigning button pins
          temp = buttonPins[j];
          buttonPins[j] = buttonPins[i];
          buttonPins[i] = temp;

          // assigning colours to corresponding indices
          //red
          temp = colourRGBValues[j][0];
          colourRGBValues[j][0] = colourRGBValues[i][0];
          colourRGBValues[i][0] = temp;

          //green
          temp = colourRGBValues[j][1];
          colourRGBValues[j][1] = colourRGBValues[i][1];
          colourRGBValues[i][1] = temp;

          //blue
          temp = colourRGBValues[j][2];
          colourRGBValues[j][2] = colourRGBValues[i][2];
          colourRGBValues[i][2] = temp;
        }// if buttonPins[j] maps to ledRGBColoursIndices[i]
      }//for loop to iterate through buttonPins
    }//for loop to iterate through ledRGBColoursIndices
}//assignButtonPins

void Buttons::lightRGBLed(int &i, bool &gameOver)
{
  if(i == numberOfCorrectButtonsPressed )
    {
      numberOfCorrectButtonsPressed++;
      analogWrite(9,colourRGBValues [i] [0]);
      analogWrite(10,colourRGBValues [i] [1]);
      analogWrite(11,colourRGBValues [i] [2]);
     }
     else
     {// wrong button pressed, game over 
       gameOver = true;
       isCorrectButtonPressed = false;
       analogWrite(9,colourRGBValues [i] [0]);
       analogWrite(10,colourRGBValues [i] [1]);
       analogWrite(11,colourRGBValues [i] [2]);
     }
}//lightRGBLed

