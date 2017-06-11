/*
  Menu.h
*/
#ifndef Menu_h
#define Menu_h

#include <Arduboy2.h>
#include "Shared.h"
#include "Assets.h"
#include "Typewriter.h"

class Menu
{
  public:
    Menu(Arduboy2 &ard);
    Shared::Gamemode loop();
  private:
    int scrollPos = 0;
    int index = 0;
    bool menuSettled = false;
    Arduboy2 &arduboy;
    const char *optionNames[3] = { "SCANNER", "POWER MNG", "DIAGNOSTIC" };
};

#endif
