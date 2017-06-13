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
  
  
  return mode;
}
