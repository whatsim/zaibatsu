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

  if (arduboy.everyXFrames(5)){
    if (arduboy.pressed(LEFT_BUTTON)) {
      cursorPos --;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
      cursorPos ++;
    }
    cursorPos += puzzleLength;
    cursorPos %= puzzleLength;
    if(digitCorrect[cursorPos] != correct){
      if (arduboy.pressed(UP_BUTTON)) {
        combo[cursorPos] ++;
      }
      if (arduboy.pressed(DOWN_BUTTON)) {
        combo[cursorPos] --;
      }
      combo[cursorPos] += 10;
      combo[cursorPos] %= 10;
    }
    if (arduboy.pressed(B_BUTTON)){
      exitTimer ++;
      if(exitTimer == 5) {
        hasPuzzle = false;
        mode = Shared::menu;
      }
    } else {
      exitTimer = 0;
    }
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
  int x = 47 + 5 * index;
  int y = 33;
  Typewriter::numAt(x,y,combo[index]);
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
  return isAllCorrect;
}
