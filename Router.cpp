/*
  Router.cpp
*/

#include "Router.h"

Router::Router()
{
  
}

Shared::Gamemode Router::loop(Arduboy2 arduboy)
{
  Shared::Gamemode mode = Shared::router;
  
  bool fiver = arduboy.everyXFrames(5);
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
