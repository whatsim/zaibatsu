/*
  Hacker.cpp 
*/

#include <Arduboy2.h>
#include "Hacker.h"

Hacker::Hacker(Arduboy2 &ard)
{
  arduboy = ard;
  printer = Typewriter();
}

void Hacker::setup()
{
  int puzzleLength = 7;
  for(int i = 0; i < puzzleLength; i++){
    int val = (int) rand() * 9;
    solution[i] = val;
  }
  
  hasPuzzle = true;
}

Shared::Gamemode Hacker::loop()
{
  if(!hasPuzzle) setup();
  printer.numAt(66,33,solution[0]);
  printer.numAt(47,33,0);
  Shared::Gamemode mode = Shared::hacker;
  return mode;
}

bool Hacker::checkPuzzle()
{
  
}
