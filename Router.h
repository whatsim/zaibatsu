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
    Router();
    Shared::Gamemode loop(Arduboy2 arduboy);
  private:
    int scrollPos = 0;
    int exitTimer = 0;
};

#endif
