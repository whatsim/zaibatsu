/*
  Menu.cpp
*/

#include "Menu.h"

Menu::Menu()
{
  
}

Shared::Gamemode Menu::loop(Arduboy2 arduboy)
{
  Shared::Gamemode mode = Shared::menu;
  bool holdDelay = arduboy.everyXFrames(30);

  menuSettled = arduboy.justPressed(B_BUTTON) || menuSettled;

  if(arduboy.justReleased(B_BUTTON) && menuSettled){
    switch(index){
      case 0 :
        mode = Shared::scanner;
      break;
      case 1 :
        mode = Shared::router;
      break;
      case 2 :
        mode = Shared::hacker;
      break;
    }
  }
  
  if(arduboy.justPressed(UP_BUTTON)){
    index ++;
    index = index % 3;
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    index --;
    index = (index + 3) % 3;
  }

  Sprites::drawSelfMasked(24,26,sprite_menuGylphs,index);
  Sprites::drawSelfMasked(109,55,sprite_confirm,0);
  
  int textLength = Typewriter::textAt(58,31,optionNames[index]) * 5;
  arduboy.drawFastHLine(51,28,textLength + 7);

  textLength = Typewriter::textAt(58,8,optionNames[(index + 1) % 3]) * 5;
  arduboy.drawFastHLine(58,9,textLength,BLACK);
  textLength = Typewriter::textAt(58,-2,optionNames[(index + 2) % 3]) * 5;
  
  return mode;
}
