/*
  Success.cpp
*/

#include "Success.h"

Success::Success()
{
  
}

Shared::Gamemode Success::loop(Arduboy2 arduboy, ArduboyTones sound)
{
  Shared::Gamemode mode = Shared::success;
  
  if(arduboy.justPressed(B_BUTTON)){
    pressedB = true;
  }
  
  if(arduboy.justReleased(A_BUTTON) || (pressedB && arduboy.justReleased(B_BUTTON))){
    pressedB = false;
    mode = Shared::title;
  }
  

  if(doChime){
    doChime = false;
    sound.tone(440, 256, 880, 256, 659, 512);
  }
  
  Sprites::drawSelfMasked(24,26,sprite_successGlyph,0);
  int textLength = Typewriter::textAt(58,31,"SUCCESSFUL") * 5;
  arduboy.drawFastHLine(51,28,textLength + 7);
  return mode;
}
