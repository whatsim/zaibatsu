/*
  Menu.cpp
*/

#include <Arduboy2.h>
#include "Menu.h"

Menu::Menu(Arduboy2 &ard)
{
  arduboy = ard;
  printer = Typewriter();
}

Shared::Gamemode Menu::loop()
{
  Shared::Gamemode mode = Shared::menu;
  if(menuSettled && arduboy.pressed(A_BUTTON)){
    switch(index){
      case 0 :
        mode = Shared::scanner;
      break;
    }
  }
  if(arduboy.pressed(UP_BUTTON)){
    index ++;
    index = index > 2 ? 2 : index;
  }
  if(arduboy.pressed(DOWN_BUTTON)){
    index --;
    index = index < 0 ? 0 : index;
  }
  Sprites::drawSelfMasked(24,26,sprite_menu,index);
  printer.textAt(0,0,"0123456789");
  printer.textAt(0,0,"ABCEDFGHIJKLM");
  printer.textAt(0,0,"NOPQRSTUVWXYZ");
  
  return mode;
}
