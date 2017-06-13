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
  Serial.println(exitTimer);
  if (arduboy.pressed(A_BUTTON) && fiver){
    // hold b to quit to menu
    exitTimer ++;
    if(exitTimer == 5) {
      // reset anything you need to on exit
      mode = Shared::menu;
    }
  } else if(!arduboy.pressed(A_BUTTON)){
    exitTimer = 0;
  }
  return mode;
}
