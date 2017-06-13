/*
  Error.cpp 
*/

#include "Error.h"

Error::Error()
{
  
}

Shared::Gamemode Error::loop(Arduboy2 arduboy, ArduboyTones sound)
{
  float yOffset = random();
  yOffset *= yOffset * yOffset;
  yOffset *= 6;
  yOffset -= 3;
  Sprites::drawSelfMasked(99,2 + yOffset,sprite_errorGlyph,0);
  
  Shared::Gamemode mode = Shared::error;

  if(arduboy.justPressed(B_BUTTON)){
    pressedB = true;
  }
  
  if(arduboy.justReleased(A_BUTTON) || (pressedB && arduboy.justReleased(B_BUTTON))){
    pressedB = false;
    mode = Shared::title;
  }
  
  if(arduboy.everyXFrames(30)){
    animationToggle = !animationToggle;
  }

  Typewriter::textAt(2,32,"SYSERROR AT 0X6826");
  Typewriter::textAt(2,40,"TO ENSURE SYSTEM INTEGRITY TERMI");
  Typewriter::textAt(2,48,"HAS BEEN DISABLED");
  if(animationToggle){
    sound.tone(110,128);
    Typewriter::textAt(2,56,"CONTACT DARPATEC SYSTEM ADMINIST");
  }
  
  return mode;
}
