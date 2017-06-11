/*
  Error.cpp 
*/

#include "Error.h"

Error::Error(Arduboy2 &ard)
{
  arduboy = ard;
}

Shared::Gamemode Error::loop()
{
  Sprites::drawSelfMasked(99,2,sprite_errorGlyph,0);
  
  Shared::Gamemode mode = Shared::error;
  
  if(arduboy.justReleased(B_BUTTON)){
    mode = Shared::title;
  }
  
  if(arduboy.everyXFrames(30)){
    animationToggle != animationToggle;
  }

  Typewriter::textAt(2,32,"SYSERROR at 0x6826");
  Typewriter::textAt(2,40,"TO ENSURE SYSTEM INTEGRITY TERMI");
  Typewriter::textAt(2,48,"HAS BEEN DISABLED");
  if(animationToggle){
    Typewriter::textAt(2,56,"CONTACT DARPATEC SYSTEM ADMINIST");
  }
  
  return mode;
}
