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
    Hacker();
    Shared::Gamemode loop(Arduboy2 arduboy);
  private:
    void setup();
    void Hacker::drawDigit(Arduboy2 arduboy,int index);
    bool checkPuzzle();
    
    bool hasPuzzle = false;
    const int puzzleLength = 5;
    int puzzleTimer = 10;
    int exitTimer = 0;
    int cursorPos = 3;
    int animater = 0;
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
