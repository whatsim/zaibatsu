/*
  Dice.cpp
*/

#include "Dice.h"

Dice::Dice()
{
  
}

Shared::Gamemode Dice::loop(Arduboy2 arduboy)
{
  Shared::Gamemode mode = Shared::dice;

  if (arduboy.justPressed(LEFT_BUTTON)) {
    cursorPos --;
    upDownRepeat = 0;
  }
  if (arduboy.justPressed(RIGHT_BUTTON)) {
    cursorPos ++;
    upDownRepeat = 0;
  }
  if (arduboy.justPressed(B_BUTTON)) {
    result = roll();
  }

  if(result != 0){
    itoa(result,buf,10);
    Typewriter::textAt(100,22,"TOTAL");
    Typewriter::textAt(100,31,buf);
    int x = 5;
    int y = 40;
    for(int i = 0; i < rolledDice; i++){
      itoa(diceResults[i],buf,10);
      x += Typewriter::textAt(x,y,buf) * 5 + 5; 
      if(x > 120){
        x = 5;
        y += 9;
      }
    }
  } else {
    rolledDice = 0;
  }

  if(arduboy.justReleased(UP_BUTTON | DOWN_BUTTON) || arduboy.justPressed(UP_BUTTON | DOWN_BUTTON)){
    upDownRepeat = 0;
  }

  if(upDownRepeat == 0){
    if (arduboy.pressed(UP_BUTTON)) {
      if(cursorPos == 0){
        numDice ++;
      } else {
        numSides ++;
      }
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
      if(cursorPos == 0){
        numDice --;
      } else {
        numSides --;
      }
    }
    numDice += 10;
    numDice %= 10;
    numSides += 20;
    numSides %= 20;
    upDownRepeat = 10;
  }

  if(upDownRepeat > 0){
    upDownRepeat--;
  }

  cursorPos += 2;
  cursorPos %= 2;
  itoa(numSides+1,buf,10);
  Typewriter::numAt(5,31,numDice);
  int printLength = Typewriter::textAt(21,31,buf);
  Typewriter::textAt(13,31,"D");

  if(cursorPos == 0){
    arduboy.drawFastHLine(5, 29, 6);
  } else {
    arduboy.drawFastHLine(21, 29, 5 * printLength + 1);
  }
  
  return mode;
}

int Dice::roll(){
  int out = 0;
  rolledDice = numDice;
  for(int i = 0; i < numDice; i++){
    diceResults[i] = random(1,numSides+2);
    out += diceResults[i];
  }
  return out;
}

