#include "buttons.h"
#include "rgbLed.h"
#include "levelLeds.h"

RGBLed rgbLed = RGBLed();
Buttons buttons = Buttons();
LevelLeds levelLeds = LevelLeds();
bool gameOver = false;// variable used to indicate if the game is over
void setup() {
Serial.begin(9600);
levelLeds.beginLevel();
rgbLed.randomiseColourSequence (levelLeds.level);
rgbLed.lightRGBLed(levelLeds.level);
}


void loop() {
  buttons.assignButtonPins(rgbLed.ledRGBColoursIndices);
  buttons.pollButtons(levelLeds.level, gameOver);
  analogWrite(9, 0);//RED
  analogWrite(10, 0);//GREEN
  analogWrite(11, 0);//BLUE

  if(!gameOver)
  {// if game is not over
    levelLeds.level++;
    if(levelLeds.level == 5) levelLeds.gameFinished();
    levelLeds.completedLevel();
    levelLeds.beginLevel();
    rgbLed.randomiseColourSequence(levelLeds.level);
    rgbLed.lightRGBLed(levelLeds.level);
  }else{
    levelLeds.gameOver();
  }
    buttons.isCorrectButtonPressed = true;// reset for each level
}