/*
  Scanner.h
*/
#ifndef Scanner_h
#define Scanner_h

#include <Arduboy2.h>
#include "Shared.h"
#include "Assets.h"

class Scanner
{
  public:
    Scanner(Arduboy2 &ard);
    Shared::Gamemode loop();
  private:
    int scrollPos = 0;
    Arduboy2 &arduboy;
};

#endif
