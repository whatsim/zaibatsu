/*
  Typewriter.cpp
*/

#include <Arduboy2.h>
#include "Typewriter.h"
#include "Assets.h"

#define CHARWIDTH 5;

Typewriter::Typewriter()
{
  
}

int Typewriter::textAt(int x,int y,char* string)
{
  int i = 0;
  char ch = string[i];
  while (ch != '\0'){
      int charIndex = ch - 48;
      if(charIndex > 9) charIndex -= 7;
      if(charIndex > 0 && charIndex < 35){
        Sprites::drawSelfMasked(x,y,sprite_pragmata,charIndex);
      }
    i++;
    x += CHARWIDTH;
    ch = string[i];
  }
  
  return i;
}

void Typewriter::numAt(int x,int y,int digit)
{
  int charIndex = digit;
  Sprites::drawSelfMasked(x,y,sprite_pragmata,digit);
}
