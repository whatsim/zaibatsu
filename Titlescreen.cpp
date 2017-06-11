/*
  Titlescreen.cpp 
*/

#include "Titlescreen.h"

Titlescreen::Titlescreen(Arduboy2 &ard)
{
  arduboy = ard;
}

void Titlescreen::enter()
{
  
}

Shared::Gamemode Titlescreen::loop()
{
  Sprites::drawSelfMasked(0,0,sprite_logo,0);
  Sprites::drawSelfMasked(0,0,sprite_logotype,0);
  Shared::Gamemode mode = Shared::title;
  
  if(arduboy.justReleased(A_BUTTON)){
    mode = Shared::menu;
  }
  
  return mode;
}
