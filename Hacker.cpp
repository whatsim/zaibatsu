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

  // move digit cursor
  if ((arduboy.pressed(LEFT_BUTTON) && fiver) || arduboy.justPressed(LEFT_BUTTON)) {
    cursorPos --;
  }
  if ((arduboy.pressed(RIGHT_BUTTON) && fiver) || arduboy.justPressed(RIGHT_BUTTON)) {
    cursorPos ++;
  }
  cursorPos += puzzleLength;
  cursorPos %= puzzleLength;

  if(digitCorrect[cursorPos] != correct){
    // can't change correct digits
    // otherwise change digit up or down, and trigger change animation
    if (((arduboy.pressed(UP_BUTTON) && fiver) || arduboy.justPressed(UP_BUTTON)) && animater == 0) {
      combo[cursorPos] ++;
      animater = 10;
      digitCorrect[cursorPos] = unchecked;
    }
    if (((arduboy.pressed(DOWN_BUTTON) && fiver) || arduboy.justPressed(DOWN_BUTTON)) && animater == 0) {
      combo[cursorPos] --;
      animater = -10;
      digitCorrect[cursorPos] = unchecked;
    }
    combo[cursorPos] += 10;
    combo[cursorPos] %= 10;
    
  }
  if (arduboy.pressed(B_BUTTON) && fiver){
    // hold b to quit to menu
    exitTimer ++;
    if(exitTimer == 5) {
      hasPuzzle = false;
      mode = Shared::menu;
    }
  } else {
    exitTimer = 0;
  }

  // draw the puzzle
  for(int i = 0; i < puzzleLength; i ++) {
    drawDigit(i);
  }
  // draw box around puzzle
  int boxWidth = (puzzleLength + 2) * 5;
  int boxMargin = (WIDTH - boxWidth) / 2;
  Shared::drawBox(arduboy,boxMargin,29,boxWidth,6);
  
  // draw background text
  Typewriter::textAt("4230246",boxMargin - 40,33);
  Typewriter::textAt("0172652",boxMargin * 2 + boxWidth,33);

  // check for correct digits, and decrement the timer
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
    // flashes the screen when the tick happens
    arduboy.invert(true);
  }

  // draw the timer
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
    // the digit isn't moving
    Typewriter::numAt(x,y,combo[index]);
  } else {
    // the digit is moving up or down
    if(animater > 0){
      animater --;
      int upDigit = (combo[index] + 11) % 10;
      Typewriter::numAt(x,y + animater - 10,upDigit );
    } else {
      animater ++;
      int downDigit = (combo[index] + 9) % 10;
      Typewriter::numAt(x,y + animater + 10,downDigit);
    }
    Typewriter::numAt(x,y + animater,combo[index]);
    Sprites::drawErase(x,y - 10,sprite_fadeUp,0);
    Sprites::drawErase(x,y + 10,sprite_fadeDown,0);
    arduboy.drawRect(x,y - 16, 5, 6, BLACK);
    arduboy.drawRect(x,y + 10, 5, 6, BLACK);
  }
  if(index == cursorPos){
    // the digit is selected
    arduboy.drawFastHLine(x, y - 2, 5);
  }
  if(digitCorrect[index] == incorrect){
    // the digit is known to be wrong
    for(int i = 1; i+=2; i < 7){
      arduboy.drawFastHLine(x, y + i, 5, BLACK); 
    }
  }
  if(digitCorrect[index] == correct){
    // the digit is right
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
