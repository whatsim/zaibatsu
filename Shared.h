/*
  Shared.h
*/
#ifndef Shared_h
#define Shared_h

#include <Arduboy2.h>

class Shared
{
  public:
    Shared();
    float lerp(float a, float b, float f);
    typedef enum Gamemode {
  	  title,
  	  menu
  	};
};

#endif
