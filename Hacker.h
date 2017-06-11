/*
  Hacker.h
*/
#ifndef Hacker_h
#define Hacker_h

#include <Arduboy2.h>
#include "Shared.h"
#include "Assets.h"
#include "Typewriter.h"

class Hacker
{
  public:
    Hacker(Arduboy2 &ard);
    Shared::Gamemode loop();
  private:
    void setup();
    void Hacker::drawDigit(int index);
    bool checkPuzzle();
    
    bool hasPuzzle = false;
    const int puzzleLength = 7;
    int puzzleTimer = 10;
    int exitTimer = 0;
    int cursorPos = 3;
    int animater = 0;
    Arduboy2 &arduboy;
    int combo[7] = { 0, 0, 0, 0, 0, 0, 0 };
    int solution[7] = { 0, 0, 0, 0, 0, 0, 0 };
    enum check {
      unchecked,
      correct,
      incorrect
    };
    check digitCorrect[7] = { unchecked };
};

#endif
