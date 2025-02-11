#ifndef levelLeds_h
#define levelLeds_h

class LevelLeds
{
  private:
    int LevelLedsPins [4] = {17, 16, 15, 14};// Pins to read light level leds

  public:
    // Constructor
    LevelLeds();

    int level = 1;

    void beginLevel();
     
    void completedLevel();

    void gameFinished();

    void gameOver();
     

}; // end of class LevelLeds

#endif