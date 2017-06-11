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
    Error(Arduboy2 &ard);
    Shared::Gamemode loop();
  private:
    int animCounter = 0;
    Arduboy2 &arduboy;
    
};

#endif
