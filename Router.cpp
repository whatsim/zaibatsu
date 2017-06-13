/*
  Router.cpp
*/

#include "Router.h"

Router::Router()
{
  
}

void Router::setup()
{
  puzzleTimer = 123;
  cursorPos = 2;
  inputPos = random(6,42);
  momentum = 0;
  for(int i = 0; i < 5; i++){
    tumblerPos[i] = random(0,42);
  }
  
  isSetup = true;
}

Shared::Gamemode Router::loop(Arduboy2 arduboy)
{
  Shared::Gamemode mode = Shared::router;
  if(!isSetup) setup();
  if(arduboy.everyXFrames(8)) {
    if(puzzleTimer > 0){
      puzzleTimer --;
    } else {
      isSetup = false;
      mode = Shared::error;
    }
  }

  if (arduboy.justPressed(LEFT_BUTTON)) {
    cursorPos --;
    momentum = 0;
  }
  if (arduboy.justPressed(RIGHT_BUTTON)) {
    cursorPos ++;
    momentum = 0;
  }
  cursorPos += 5;
  cursorPos %= 5;
  
  if (arduboy.pressed(UP_BUTTON)) {
    momentum = momentum > 0 ? 0 : momentum;
    momentum -= 0.1;
  }
  if (arduboy.pressed(DOWN_BUTTON)) {
    momentum = momentum < 0 ? 0 : momentum;
    momentum += 0.1;
  }
  
  tumblerPos[cursorPos] += momentum;
  if(cursorPos - 1 >= 0){
    tumblerPos[cursorPos-1] += momentum/2;
    tumblerPos[cursorPos-1] = tumblerPos[cursorPos-1] > 0 ? tumblerPos[cursorPos-1] : 0;
    tumblerPos[cursorPos-1] = tumblerPos[cursorPos-1] < 42 ? tumblerPos[cursorPos-1] : 42;
  }
  if(cursorPos + 1 < 5){
    tumblerPos[cursorPos+1] += momentum/2;
    tumblerPos[cursorPos+1] = tumblerPos[cursorPos+1] > 0 ? tumblerPos[cursorPos+1] : 0;
    tumblerPos[cursorPos+1] = tumblerPos[cursorPos+1] < 42 ? tumblerPos[cursorPos+1] : 42;
  }
  tumblerPos[cursorPos] = tumblerPos[cursorPos] > 0 ? tumblerPos[cursorPos] : 0;
  tumblerPos[cursorPos] = tumblerPos[cursorPos] < 42 ? tumblerPos[cursorPos] : 42;
  
  momentum *= 0.9;
  
  drawTimer(arduboy);
  drawBoard(arduboy);

  if(checkBoard()){
    mode = Shared::success;
    isSetup = false;
  }

  return mode;
}

void Router::drawBoard(Arduboy2 arduboy)
{
   arduboy.drawRect(37,3,2,49);
   arduboy.drawRect(89,3,2,49);
   int startX = 40;
   int usedX = 0;
   for(int i = 0; i < 5; i++){
    int w = 7;
    if(i == cursorPos){
      w = 12;
    }
    arduboy.drawFastVLine(startX + usedX, 3, 49);
    arduboy.drawFastVLine(startX + usedX + w - 1, 3, 49);
    arduboy.drawFastHLine(startX + usedX + 2, 4, w - 4);
    arduboy.drawFastHLine(startX + usedX + 2, 50, w - 4);

    arduboy.drawFastHLine(startX + usedX + 1, 6+tumblerPos[i]-2, w - 2);
    arduboy.drawFastHLine(startX + usedX + 1, 6+tumblerPos[i]+2, w - 2);
    Sprites::drawSelfMasked(28,inputPos,sprite_arrow,0);
    Sprites::drawSelfMasked(89,inputPos,sprite_end,0);
    usedX += w + 2;
   }
}

void Router::drawTimer(Arduboy2 arduboy)
{
   arduboy.drawFastHLine(0,61,puzzleTimer);
   arduboy.drawFastHLine(puzzleTimer + 2,61,1);
   arduboy.drawFastVLine(125,61,3);
}

bool Router::checkBoard(){
  bool isAllCorrect = true;
  for(int i = 0; i < 5; i++){
    bool isCorrect = tumblerPos - 2 < inputPos && tumblerPos + 2 > inputPos;
    isAllCorrect = isAllCorrect && isCorrect;
  }
  return isAllCorrect;
}

