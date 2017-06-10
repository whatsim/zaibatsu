/*
  Titlescreen.cpp 
*/

#include <Arduboy2.h>
#include "Titlescreen.h"
#include "Assets.h"

Titlescreen::Titlescreen(Arduboy2 &ard)
{
  animCounter = 0;
  arduboy = ard;
}

void Titlescreen::enter()
{
  
}

Shared::Gamemode Titlescreen::loop()
{
  Sprites::drawSelfMasked(0,0,sprite_logo,1);
  Sprites::drawSelfMasked(0,0,sprite_logotype,1);
  Shared::Gamemode mode = Shared::title;
  if(arduboy.pressed(A_BUTTON)){
    mode = Shared::menu;
  }
  return mode;
}
