/*
  Menu.h
*/
#ifndef Menu_h
#define Menu_h

#include <Arduboy2.h>
#include "Shared.h"

class Menu
{
  public:
    Menu(Arduboy2 &ard);
    Shared::Gamemode loop();
  private:
    int scrollPos;
    int index;
    Arduboy2 &arduboy;
};

#endif
