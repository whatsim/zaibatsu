/*
  Success.h
*/
#ifndef Success_h
#define Success_h

#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "Shared.h"
#include "Assets.h"
#include "Typewriter.h"

class Success
{
  public:
    Success();
    Shared::Gamemode loop(Arduboy2 arduboy, ArduboyTones sound);
    bool doChime = false;
    bool pressedB = false;
    
};

#endif
