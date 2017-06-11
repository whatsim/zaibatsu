/*
  Hacker.cpp 
*/

#include "Hacker.h"

Hacker::Hacker(Arduboy2 &ard)
{
  arduboy = ard;
}

void Hacker::setup()
{
  for(int i = 0; i < puzzleLength; i++){
    int val = (int) rand() * 9;
    solution[i] = val;
  }
  
  hasPuzzle = true;
}

Shared::Gamemode Hacker::loop()
{
  if(!hasPuzzle) setup();
  Shared::Gamemode mode = Shared::hacker;

  bool fiver = arduboy.everyXFrames(5);
  
  if ((arduboy.pressed(LEFT_BUTTON) && fiver) || arduboy.justPressed(LEFT_BUTTON)) {
    cursorPos --;
  }
  if ((arduboy.pressed(RIGHT_BUTTON) && fiver) || arduboy.justPressed(RIGHT_BUTTON)) {
    cursorPos ++;
  }
  cursorPos += puzzleLength;
  cursorPos %= puzzleLength;
  if(digitCorrect[cursorPos] != correct){
    if (((arduboy.pressed(UP_BUTTON) && fiver) || arduboy.justPressed(UP_BUTTON)) && animater == 0) {
      combo[cursorPos] ++;
      animater = 10;
    }
    if (((arduboy.pressed(DOWN_BUTTON) && fiver) || arduboy.justPressed(DOWN_BUTTON)) && animater == 0) {
      combo[cursorPos] --;
      animater = -10;
    }
    combo[cursorPos] += 10;
    combo[cursorPos] %= 10;
  }
  if (arduboy.pressed(B_BUTTON) && fiver){
    exitTimer ++;
    if(exitTimer == 5) {
      hasPuzzle = false;
      mode = Shared::menu;
    }
  } else {
    exitTimer = 0;
  }

  
  for(int i = 0; i < puzzleLength; i ++) {
    drawDigit(i);
  }
  
  if (arduboy.everyXFrames(75)) { // every 5 seconds
    bool isRight = checkPuzzle();
    puzzleTimer --;
    if(puzzleTimer == 0){
      mode = Shared::error;
      // you lose
    }
    if(isRight) {
      hasPuzzle = false;
      mode = Shared::success;
      // you did it
    }
  }
  
  for(int i = 0; i < puzzleTimer; i ++){
    arduboy.drawRect(24 + puzzleTimer * 10, 59, 9, 1);
  }
  return mode;
}

void Hacker::drawDigit(int index){
  int startX = (WIDTH - (puzzleLength * 5))/2;
  int x = startX + 5 * index;
  int y = 33;
  if(animater == 0){
    Typewriter::numAt(x,y,combo[index]);
  } else {
    if(animater > 0){
      animater --;
      Typewriter::numAt(x,y + animater - 10,combo[index]+1);
    } else {
      animater ++;
      Typewriter::numAt(x,y + animater + 10,combo[index]-1);
    }
    Typewriter::numAt(x,y + animater,combo[index]);
    Sprites::drawErase(x,y - 10,sprite_fadeUp,0);
    Sprites::drawErase(x,y + 10,sprite_fadeDown,0);
    arduboy.drawRect(x,y - 16, 5, 6, BLACK);
    arduboy.drawRect(x,y + 10, 5, 6, BLACK);
  }
  if(index == cursorPos){
    arduboy.drawFastHLine(x, y - 2, 5);
  }
  if(digitCorrect[index] == incorrect){
    for(int i = 1; i+=2; i < 7){
      arduboy.drawFastHLine(x, y + i, 5, BLACK); 
    }
  }
  if(digitCorrect[index] == correct){
    arduboy.drawFastHLine(x, y + 7, 5);
  }
}

bool Hacker::checkPuzzle()
{
  bool isAllCorrect = true;
  for(int i = 0; i < puzzleLength; i++){
    bool isCorrect = solution[i] == combo[i];
    digitCorrect[i] = isCorrect ? correct : incorrect;
    isAllCorrect = isAllCorrect && isCorrect;
  }
  arduboy.invert(true);
  return isAllCorrect;
}
