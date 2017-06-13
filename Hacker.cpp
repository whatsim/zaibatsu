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
  for(int i = 0; i < puzzleLength; i++){
    solution[i] = values[i];
    combo[i] = 0;  
    digitCorrect[i] = unchecked;
  }
  puzzleTimer = 10;
  hasPuzzle = true;
}

Shared::Gamemode Hacker::loop(Arduboy2 arduboy)
{
  if(!hasPuzzle) setup();
  Shared::Gamemode mode = Shared::hacker;

  bool repeatDelay = arduboy.everyXFrames(15);

  // move digit cursor
  if (((arduboy.pressed(LEFT_BUTTON) && repeatDelay) || arduboy.justPressed(LEFT_BUTTON)) && animater == 0) {
    cursorPos --;
  }
  if (((arduboy.pressed(RIGHT_BUTTON) && repeatDelay) || arduboy.justPressed(RIGHT_BUTTON)) && animater == 0) {
    cursorPos ++;
  }
  cursorPos += puzzleLength;
  cursorPos %= puzzleLength;

  if(digitCorrect[cursorPos] != correct){
    // can't change correct digits
    // otherwise change digit up or down, and trigger change animation
    if (arduboy.justPressed(UP_BUTTON) && animater == 0) {
      combo[cursorPos] ++;
      animater = 20;
      digitCorrect[cursorPos] = unchecked;
    }
    if (arduboy.justPressed(DOWN_BUTTON) && animater == 0) {
      combo[cursorPos] --;
      animater = -20;
      digitCorrect[cursorPos] = unchecked;
    }
    combo[cursorPos] += 10;
    combo[cursorPos] %= 10;
  }
  if (arduboy.pressed(A_BUTTON) && repeatDelay){
    // hold b to quit to menu
    exitTimer ++;
    if(exitTimer == 5) {
      hasPuzzle = false;
      
      mode = Shared::menu;
    }
  } else if(!arduboy.pressed(A_BUTTON)){
    exitTimer = 0;
  }

  // draw the puzzle
  for(int i = 0; i < puzzleLength; i ++) {
    drawDigit(arduboy,i);
  }
  // draw box around puzzle
  int boxWidth = (puzzleLength + 2) * 5;
  int boxMargin = (WIDTH - boxWidth) / 2;
  arduboy.drawRect(boxMargin,29,boxWidth + 1,15);
  
  // draw background text
  Typewriter::textAt("4230246",boxMargin - 40,33);
  Typewriter::textAt("0172652",boxMargin * 2 + boxWidth,33);

  if(arduboy.justReleased(A_BUTTON)){
    bool isRight = checkPuzzle();
    puzzleTimer --;
    if(puzzleTimer == 0){
      hasPuzzle = false;
      mode = Shared::error;
      // you lose
    }
    if(isRight) {
      hasPuzzle = false;
      mode = Shared::success;
      // you did it
    }
  }
   
  // draw the timer
  for(int i = 0; i < puzzleTimer; i ++){
    arduboy.drawRect(14 + i * 10, 59, 9, 1);
  }
  return mode;
}

void Hacker::drawDigit(Arduboy2 arduboy,int index){
  int startX = (WIDTH - (puzzleLength * 5))/2;
  int x = startX + 5 * index;
  int y = 33;
  if(animater == 0 || index != cursorPos){
    // the digit isn't moving
    Typewriter::numAt(x,y,combo[index]);
  } else {
    // the digit is moving up or down
    
    if(animater > 0){
      animater -=2;
      int upDigit = (combo[index] + 9) % 10;
      Typewriter::numAt(x,y + animater - 20,upDigit );
    } else {
      animater +=2;
      int downDigit = (combo[index] + 11) % 10;
      Typewriter::numAt(x,y + animater + 20,downDigit);
    }
    Typewriter::numAt(x,y + animater,combo[index]);
    Sprites::drawErase(x,y - 10,sprite_fadeUp,0);
    Sprites::drawErase(x,y + 9,sprite_fadeDown,0);
    arduboy.fillRect(x,y - 20, 5, 10, BLACK);
    arduboy.fillRect(x,y + 17, 5, 10, BLACK);
  }
  if(index == cursorPos){
    // the digit is selected
    arduboy.drawFastHLine(x, y - 2, 6);
  }
  if(digitCorrect[index] == incorrect){
    // the digit is known to be wrong
    for(int i = 1; i < 7; i+= 2){
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
