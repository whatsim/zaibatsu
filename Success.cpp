/*
  Success.cpp
*/

#include "Success.h"

Success::Success(Arduboy2 &ard)
{
  arduboy = ard;
}

Shared::Gamemode Success::loop()
{
  Shared::Gamemode mode = Shared::success;
  
  if(arduboy.justReleased(A_BUTTON)){
    mode = Shared::menu; 
  }
  
  Sprites::drawSelfMasked(24,26,sprite_successGlyph,0);
  int textLength = Typewriter::textAt(58,31,"Success") * 5;
  arduboy.drawFastHLine(58,29,textLength);
  
  return mode;
}
