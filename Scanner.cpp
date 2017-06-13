/*
  Scanner.cpp
*/

#include "Scanner.h"

Scanner::Scanner()
{
  
}

Shared::Gamemode Scanner::loop(Arduboy2 arduboy)
{
  Shared::Gamemode mode = Shared::scanner;
  bool fiver = arduboy.everyXFrames(5);
  
  
  return mode;
}
