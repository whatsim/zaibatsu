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
    void drawMeter(Arduboy2 arduboy);
    void drawPing(Arduboy2 arduboy);
    void drawTarget(Arduboy2 arduboy);
    void drawTickAtAngle(Arduboy2 arduboy, float angle);
    void setup();
    void placeTarget();
    bool hitTarget();
    int scanPercent = 0;
    int charges = 4;
    float pingAngle = 0;
    bool isSetup;
    bool isSweeping = false;
    float targetAngle = 0;
    float targetAperture = 0;
};

#endif
