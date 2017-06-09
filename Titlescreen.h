/*
  Titlescreen.h
*/
#ifndef Titlescreen_h
#define Titlescreen_h

#include <Arduboy2.h>
#include "Shared.h"

class Titlescreen
{
  public:
    Titlescreen(Arduboy2 &ard);
    void enter();
    Shared::Gamemode loop();
  private:
    int animCounter;
    Arduboy2 &arduboy;
};

#endif
