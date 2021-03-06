/*
  Hacker.cpp 
*/

#include "Hacker.h"

Hacker::Hacker()
{
  
}

void Hacker::setup()
{
  int values[10] = {0,1,2,3,4,5,6,7,8,9};
  Shared::shuffle(values,10);
  int comboValues[10] = {0,1,2,3,4,5,6,7,8,9};
  Shared::shuffle(comboValues,10);
  
  for(int i = 0; i < puzzleLength; i++){
    solution[i] = values[i];
    combo[i] = comboValues[i];  
    digitCorrect[i] = unchecked;
  }
  puzzleTimer = 5;
  checkTimer = 0;
  cursorPos = 3;
  hasPuzzle = true;
  ended = false;
  wasRight = false;
  endTimer = 90;
}

Shared::Gamemode Hacker::loop(Arduboy2 arduboy, ArduboyTones sound)
{
  if(!hasPuzzle) setup();
  Shared::Gamemode mode = Shared::hacker;

  

  // move digit cursor
  if (!ended  && arduboy.justPressed(LEFT_BUTTON) && abs(animater) < 4) {
    cursorPos --;
    while(digitCorrect[cursorPos] == correct && cursorPos > 0) cursorPos --;
    animater = 0;
  }
  if (!ended  && arduboy.justPressed(RIGHT_BUTTON) && abs(animater) < 4) {
    cursorPos ++;
    while(digitCorrect[cursorPos] == correct && cursorPos < puzzleLength) cursorPos ++;
    animater = 0;
  }
  cursorPos += puzzleLength;
  cursorPos %= puzzleLength;

  

  if(!ended  && digitCorrect[cursorPos] != correct){
    // can't change correct digits
    // otherwise change digit up or down, and trigger change animation
    if (arduboy.pressed(UP_BUTTON) && animater == 0) {
      combo[cursorPos] ++;
      animater = 18;
      digitCorrect[cursorPos] = unchecked;
    }
    if (arduboy.pressed(DOWN_BUTTON) && animater == 0) {
      combo[cursorPos] --;
      animater = -18;
      digitCorrect[cursorPos] = unchecked;
    }
    combo[cursorPos] += 10;
    combo[cursorPos] %= 10;
  }
  

  // draw the puzzle
  for(int i = 0; i < puzzleLength; i ++) {
    drawDigit(arduboy,i);
  }
  // draw box around puzzle
  int boxWidth = (puzzleLength + 2) * 5;
  int boxMargin = (WIDTH - boxWidth) / 2;
  arduboy.drawRect(boxMargin,27,boxWidth + 1,15);
  
  // draw background text

  if(arduboy.everyXFrames(10)){
    int leftValues[10] = {0,1,2,3,4,5,6,7,8,9};
    Shared::shuffle(leftValues,10);
    int rightValues[10] = {0,1,2,3,4,5,6,7,8,9};
    Shared::shuffle(rightValues,10);
    for(int i = 0; i < puzzleLength; i++){
      leftNoise[i] = leftValues[i];
      rightNoise[i] = rightValues[i];
    }
  }

  for(int i = 0; i < 7; i++){
    Typewriter::numAt(boxMargin - 40 + i*5,31,leftNoise[i]);
    Typewriter::numAt(boxMargin + boxWidth + 5 + i*5,31,rightNoise[i]);
  }
  
  if(!ended  && (arduboy.justReleased(B_BUTTON) || checkTimer == 140)){
    sound.tone(440,50);
    arduboy.invert(true);
    bool isRight = checkPuzzle();
    puzzleTimer --;
    if(puzzleTimer == 0 || isRight){
      ended = true;
      wasRight = isRight;
    }
    checkTimer = 0;
  } else {
    checkTimer ++;
  }
   
  // draw the timer
  if(!ended){
    for(int i = 0; i < puzzleTimer; i ++){
      int timerX = (128 - puzzleTimer * 10) / 2;
      arduboy.drawRect(timerX + i * 10, 59, 9, 1);
    }
  }
  if(ended){
    endTimer --;
    if(endTimer <= 0){
      hasPuzzle = false;
      if(!wasRight){
        mode = Shared::error;
      } else {
        mode = Shared::success;
      }
    }
  }
  
  return mode;
}

void Hacker::drawDigit(Arduboy2 arduboy,int index){
  int startX = (WIDTH - (puzzleLength * 5))/2;
  int x = startX + 5 * index;
  int y = 31;
  if(animater == 0 || index != cursorPos){
    // the digit isn't moving
    Typewriter::numAt(x,y,combo[index]);
  } else {
    // the digit is moving up or down
    
    if(animater > 0){
      animater -=3;
      int upDigit = (combo[index] + 9) % 10;
      Typewriter::numAt(x,y + animater - 18,upDigit );
    } else {
      animater +=3;
      int downDigit = (combo[index] + 11) % 10;
      Typewriter::numAt(x,y + animater + 18,downDigit);
    }
    Typewriter::numAt(x,y + animater,combo[index]);
    Sprites::drawErase(x,y - 10,sprite_fadeUp,0);
    Sprites::drawErase(x,y + 9,sprite_fadeDown,0);
    arduboy.fillRect(x,y - 20, 5, 10, BLACK);
    arduboy.fillRect(x,y + 17, 5, 10, BLACK);
  }
  if(!ended && index == cursorPos){
    // the digit is selected
    arduboy.drawFastHLine(x, y - 2, 6);
  }
  if(digitCorrect[index] == incorrect){
    // the digit is known to be wrong
    if(solution[index] > combo[index]){
      arduboy.fillTriangle(x+1,y-6,x+5,y-6,x+3,y-8);
    } else {
      arduboy.fillTriangle(x+1,y+12,x+5,y+12,x+3,y+14);
    }
    for(int i = 1; i <= 7; i+= 2){
      arduboy.drawFastHLine(x+1, y + i, 5, BLACK); 
    }  

  }
  if(digitCorrect[index] == correct){
    // the digit is right
    arduboy.drawFastHLine(x, y + 8, 6);
  }
}

bool Hacker::checkPuzzle()
{
  bool isAllCorrect = true;
  for(int i = 0; i < puzzleLength; i++){
    bool isCorrect = solution[i] == combo[i];
    digitCorrect[i] = isCorrect ? correct: incorrect;
    isAllCorrect = isAllCorrect && isCorrect;
  }
  return isAllCorrect;
}
