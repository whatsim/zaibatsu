/*
  Titlescreen.h
*/
#ifndef Titlescreen_h
#define Titlescreen_h

#include <Arduboy2.h>
#include "Shared.h"
#include "Assets.h"

class Titlescreen
{
  public:
    Titlescreen();
    void enter();
    Shared::Gamemode loop(Arduboy2 arduboy);
  private:
    int animCounter = 0;
    
};

#endif
