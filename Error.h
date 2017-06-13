/*
  Error.h
*/
#ifndef Error_h
#define Error_h

#include <Arduboy2.h>
#include "Shared.h"
#include "Assets.h"
#include "Typewriter.h"

class Error
{
  public:
    Error();
    Shared::Gamemode loop(Arduboy2 arduboy);
  private:
    int animCounter = 0;
    bool animationToggle = false;
    
};

#endif
