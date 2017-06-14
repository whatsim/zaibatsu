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
    bool isSetup = false;
  private:
    void setup();
    void drawMeter(Arduboy2 arduboy);
    void drawPing(Arduboy2 arduboy);
    void drawTarget(Arduboy2 arduboy);
    void drawTickAtAngle(Arduboy2 arduboy, float angle);
    void placeTarget();
    bool hitTarget();
    int scanPercent = 0;
    int charges = 4;
    float pingAngle = 0;
    bool isSweeping = false;
    float targetAngle = 0;
    float targetAperture = 0;
    bool ended = false;
    int endTimer = 90;
};

#endif
