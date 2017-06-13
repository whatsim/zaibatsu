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
    Scanner();
    Shared::Gamemode loop(Arduboy2 arduboy);
  private:
    int scrollPos = 0;
};

#endif
