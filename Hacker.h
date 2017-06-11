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
    bool hasPuzzle = false;
    int puzzleTimer = 0;
    Arduboy2 &arduboy;
    Typewriter printer;
    int combo[7] = { 0, 0, 0, 0, 0, 0, 0 };
    int solution[7] = { 0, 0, 0, 0, 0, 0, 0 };
    bool checkPuzzle();
};

#endif
