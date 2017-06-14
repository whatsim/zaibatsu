/*
  Router.h
*/
#ifndef Router_h
#define Router_h

#include <Arduboy2.h>
#include "Shared.h"
#include "Assets.h"

class Router
{
  public:
    Router();
    Shared::Gamemode loop(Arduboy2 arduboy);
    bool isSetup = false;
  private:
    void setup();
    void drawBoard(Arduboy2 arduboy);
    void drawTimer(Arduboy2 arduboy);
    bool checkBoard();
    int puzzleTimer = 123;
    int cursorPos = 2;
    int inputPos = 22;
    int exitTimer = 60;
    float momentum = 0;
    float tumblerPos[5] = {22,22,22,22,22};
    bool tumblerInPlace[5] = {false,false,false,false,false};
    float tumblerDivisors[5] = { 1, 1, 1, 1, 1 };
    
    
};

#endif
