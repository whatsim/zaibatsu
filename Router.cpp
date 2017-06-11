/*
  Router.cpp
*/

#include "Router.h"

Router::Router(Arduboy2 &ard)
{
  arduboy = ard;
}

Shared::Gamemode Router::loop()
{
  Shared::Gamemode mode = Shared::router;
  
  bool fiver = arduboy.everyXFrames(5);
  if (arduboy.pressed(B_BUTTON) && fiver){
    // hold b to quit to menu
    exitTimer ++;
    if(exitTimer == 5) {
      // reset anything you need to on exit
      mode = Shared::menu;
    }
  } else {
    exitTimer = 0;
  }
  
  return mode;
}
