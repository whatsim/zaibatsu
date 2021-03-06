/*
  Hacker.h
*/
#ifndef Hacker_h
#define Hacker_h

#include <Arduboy2.h>
#include <ArduboyTones.h>

#include "Shared.h"
#include "Assets.h"
#include "Typewriter.h"

class Hacker
{
  public:
    Hacker();
    Shared::Gamemode loop(Arduboy2 arduboy, ArduboyTones sound);
    bool hasPuzzle = false;
  private:
    void setup();
    void Hacker::drawDigit(Arduboy2 arduboy,int index);
    bool checkPuzzle();
    
    const int puzzleLength = 7;
    int puzzleTimer = 5;
    int checkTimer = 0;
    int cursorPos = 3;
    int animater = 0;
    int combo[7] = { 5, 5, 5, 5, 5, 5, 5 };
    int solution[7] = { 0, 0, 0, 0, 0, 0, 0 };
    int leftNoise[7] = { 2, 6, 3, 0, 9, 7, 3 };
    int rightNoise[7] = { 1, 8, 6, 9, 0, 3, 2 };
    enum check {
      unchecked,
      correct,
      incorrect
    };
    check digitCorrect[7] = { unchecked };
    bool ended = false;
    bool wasRight = false;
    int endTimer = 90;
};

#endif
