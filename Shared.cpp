/*
  Shared.cpp
*/

#include "Shared.h"

float Shared::lerp(float a, float b, float f)
{
    return a + f * (b - a);
}
void Shared::drawBox(Arduboy2 &arduboy, int x,int y,int w,int h,int color = WHITE){
  arduboy.drawFastHLine(x,y,w,color);
  arduboy.drawFastVLine(x,y,h,color);
  arduboy.drawFastHLine(x,y+h,w,color);
  arduboy.drawFastVLine(x + w,y,h,color);
}

