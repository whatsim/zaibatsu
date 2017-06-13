/*
  Success.cpp
*/

#include "Success.h"

Success::Success()
{
  
}

Shared::Gamemode Success::loop(Arduboy2 arduboy)
{
  Shared::Gamemode mode = Shared::success;
  
  if(arduboy.justReleased(A_BUTTON)){
    mode = Shared::menu; 
  }
  
  Sprites::drawSelfMasked(24,26,sprite_successGlyph,0);
  int textLength = Typewriter::textAt(58,31,"SUCCESSFUL") * 5;
  arduboy.drawFastHLine(51,28,textLength + 7);
  return mode;
}
