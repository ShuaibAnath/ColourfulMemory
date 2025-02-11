#ifndef rgbLed_h
#define rgbLed_h

class RGBLed
{
  private:

  const int RED_RGB_PIN = 9;
  const int GREEN_RGB_PIN = 10;
  const int BLUE_RGB_PIN = 11;

  public:
     /*                                 White,       Orange,        Blue,       Green,        Yellow,         Magenta,      Red */
     const int colourRGBValues[7][3] = {{255, 255, 255}, {255, 100, 0}, {0, 0, 255}, {0, 255, 0}, {255, 255, 0}, {255, 0, 255}, {255, 0, 0}};  /*Array consists of elements which represent 
     the RGB values of the corresponding indices of colours array*/ 
     
     int ledRGBColoursIndices [7] = {0, 1, 2, 3, 4, 5, 6};// array that determines the sequence of colours for RGBLED lighting 
  
     RGBLed(); // constructor

     void randomiseColourSequence (int &level);//randomises colours array and colourRGBValues array columns

     void populateledRGBColoursIndices(int &arrayMembersLeft, int numberOfMembersLeftAfterInsert, int arrayPins[], int &i, int minRandNumber, int maxRandNumber);

     void lightRGBLed(int &level);
}; // end of class RGBLed

#endif