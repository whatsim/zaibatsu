/*
  Menu.cpp
*/

#include <Arduboy2.h>
#include "Menu.h"

Menu::Menu(Arduboy2 &ard)
{
  arduboy = ard;
  scrollPos = 0;
  index = 0;
}

Shared::Gamemode Menu::loop()
{
  Shared::Gamemode mode = Shared::menu;
  return mode;
}
