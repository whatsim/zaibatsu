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
      case 1 :
        mode = Shared::router;
      case 2 :
        mode = Shared::hacker;
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
  Sprites::drawSelfMasked(24,26,sprite_menuGylphs,index);
  printer.textAt(58,31,"SCANNER");
  printer.textAt(0,0,"0123456789");
  printer.textAt(0,5,"ABCEDFGHIJKLM");
  printer.textAt(0,10,"NOPQRSTUVWXYZ");
  
  return mode;
}
