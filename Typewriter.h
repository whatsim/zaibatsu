/*
  Typewriter.h
*/
#ifndef Typewriter_h
#define Typewriter_h

#include <Arduboy2.h>
#include "Shared.h"

class Typewriter
{
  public:
    Typewriter();
    int textAt(int x,int y,char* string);
    
};

#endif
