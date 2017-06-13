/*
  Error.h
*/
#ifndef Error_h
#define Error_h

#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "Shared.h"
#include "Assets.h"
#include "Typewriter.h"

class Error
{
  public:
    Error();
    Shared::Gamemode loop(Arduboy2 arduboy, ArduboyTones sound);
  private:
    bool animationToggle = false;
    bool pressedB = false;
    
};

#endif
