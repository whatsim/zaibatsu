/*
  Scanner.cpp
*/

#include "Scanner.h"

Scanner::Scanner(Arduboy2 &ard)
{
  arduboy = ard;
}

Shared::Gamemode Scanner::loop()
{
  Shared::Gamemode mode = Shared::scanner;
  
  return mode;
}
