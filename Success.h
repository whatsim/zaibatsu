/*
  Success.h
*/
#ifndef Success_h
#define Success_h

#include <Arduboy2.h>
#include "Shared.h"
#include "Assets.h"
#include "Typewriter.h"

class Success
{
  public:
    Success(Arduboy2 &ard);
    Shared::Gamemode loop();
  private:
    Arduboy2 &arduboy;
};

#endif
