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
  
  return mode;
}
