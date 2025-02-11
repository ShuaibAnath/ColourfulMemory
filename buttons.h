#ifndef buttons_h
#define buttons_h

class Buttons
{
  private:
    int buttonPins [7] = {2, 3, 4, 5, 6, 7, 8};// Pins to give the state of the button

    /*                                  White,       Orange,        Blue,       Green,        Yellow,         Magenta,      Red */
     int colourRGBValues[7][3] = {{255, 255, 255}, {255, 100, 0}, {0, 0, 255}, {0, 255, 0}, {255, 255, 0}, {255, 0, 255}, {255, 0, 0}};  /*Array consists of elements which represent 
     the RGB values of the corresponding indices of colours array*/ 

    int buttonStates [7]; // checks which buttons are pressed


    int lastButtonStates [7] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW};// for button debouncing

    unsigned long lastDebounceTime = 0;  // the last tifme the output pin was toggled

    unsigned long debounceDelay = 50;    // the debounce time in milliseconds
  
  public:
    // Constructor
    Buttons();

    bool isCorrectButtonPressed = true;// Initially true until wrong button is pressed

    int numberOfCorrectButtonsPressed = 0;// used to check how many buttons have been pressed in the correct order  

    void pollButtons(int &level, bool &gameOver);// Checks if any buttons have gone high 

    void lightRGBLed(int &i, bool &gameOver); //Checks if the buttons are being pressed in the correct order.

    void assignButtonPins(int* ledRGBColoursIndices);// maps buttonPins in same order as colours shown on RGB LED

}; // end of class sequenceGenerator

#endif