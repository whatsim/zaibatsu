/*
  Shared.h
*/
#ifndef Shared_h
#define Shared_h

#include <Arduboy2.h>

namespace Shared
{
    float lerp(float a, float b, float f);
    void drawBox(Arduboy2 &arduboy, int x,int y,int w,int h,int color = WHITE);
    typedef enum Gamemode {
  	  title,
  	  menu,
  	  scanner,
      router,
      hacker,
      success,
      error
  	};
};

#endif
