/*
  Router.h
*/
#ifndef Router_h
#define Router_h

#include <Arduboy2.h>
#include "Shared.h"
#include "Assets.h"

class Router
{
  public:
    Router(Arduboy2 &ard);
    Shared::Gamemode loop();
  private:
    int scrollPos = 0;
    Arduboy2 &arduboy;
};

#endif
