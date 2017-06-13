/*
  Titlescreen.cpp 
*/

#include "Titlescreen.h"

Titlescreen::Titlescreen()
{
  
}

void Titlescreen::enter()
{
  
}

Shared::Gamemode Titlescreen::loop(Arduboy2 arduboy)
{
  Sprites::drawSelfMasked(37,15,sprite_logo,0);
  Sprites::drawSelfMasked(38 + random(1),43,sprite_logotype,0);
  Shared::Gamemode mode = Shared::title;
  
  if(arduboy.pressed(B_BUTTON)){
    arduboy.invert(true);
  }
  if(arduboy.justReleased(B_BUTTON)){
    mode = Shared::menu;
  }
  
  return mode;
}
