/*
  Scanner.cpp
*/

#include "Scanner.h"

Scanner::Scanner()
{

}

void Scanner::setup()
{
  scanPercent = 0;
  charges = 4;
  pingAngle = 0;
  isSetup = true;
  placeTarget();
}

Shared::Gamemode Scanner::loop(Arduboy2 arduboy)
{
  Shared::Gamemode mode = Shared::scanner;
  if(!isSetup) setup();
  
  if(arduboy.justPressed(B_BUTTON)){
    if(isSweeping){
      
      if(hitTarget()){
        scanPercent += 9;
        if(abs(pingAngle - targetAngle) < 0.1) charges ++;
      }
      pingAngle = PI;
      isSweeping = false;
      placeTarget();
    } else if(charges > 0){
      charges --;
      pingAngle = PI;
      isSweeping = true;
    }
  }
  if(scanPercent > 0 && arduboy.everyXFrames(5)){
    scanPercent --;
  }
  if(pingAngle < 2 * PI){
    pingAngle += 0.10;
  } else {
    isSweeping = false;
  }

  Sprites::drawSelfMasked(37,24,sprite_scanner,random(3));
  Sprites::drawSelfMasked(2,56,sprite_charges,charges);

  if(isSweeping){
    drawPing(arduboy);
  }
  drawMeter(arduboy);
  drawTarget(arduboy);

  if(charges < 1 && scanPercent == 0 && !isSweeping){
      isSetup = false;
      mode = Shared::error;
  }
  if(scanPercent > 32){
    isSetup = false;
    mode = Shared::success;
  }
  
  return mode;
}

void Scanner::drawMeter(Arduboy2 arduboy){
  arduboy.drawFastHLine(90,50,2);
  arduboy.drawFastHLine(93,50,2);
  arduboy.drawFastHLine(96,50,2);
  arduboy.drawFastHLine(99,50,2);
  arduboy.drawFastHLine(102,50,5);
  arduboy.drawFastHLine(101,19,1);
  arduboy.drawFastHLine(107,19,3);
  if(scanPercent < 23) {
    arduboy.fillRect(103,26 + (23 - scanPercent),3,scanPercent);
  } else {
    arduboy.fillRect(103,26,3,23);
  }
  if(scanPercent > 23){
    if(scanPercent < 29){
      arduboy.fillRect(103,20 + (29 - scanPercent),3,scanPercent - 24);
    } else {
      arduboy.fillRect(103,20,3,5);
    }
  }
  if(scanPercent > 30){
    if(scanPercent < 32){
      arduboy.fillRect(103,17 + (32 - scanPercent),3,scanPercent - 30);
    } else {
      arduboy.fillRect(103,17,3,2);
    }
  }
}

void Scanner::drawPing(Arduboy2 arduboy){
  float x = 63 + cos(pingAngle) * 35;
  float y = 48 + sin(pingAngle) * 35;
  arduboy.drawLine(x,y,64,48);
  arduboy.drawLine(x-1,y-1,63,47,BLACK);
  arduboy.drawLine(x-2,y-1,63,47,BLACK);
}

void Scanner::drawTarget(Arduboy2 arduboy){
  drawTickAtAngle(arduboy, targetAngle);
  drawTickAtAngle(arduboy, targetAngle - targetAperture);
  drawTickAtAngle(arduboy, targetAngle + targetAperture);
}

void Scanner::drawTickAtAngle(Arduboy2 arduboy,float angle){
  float oX = 63 + cos(angle) * 35;
  float oY = 48 + sin(angle) * 35;
  float iX = 63 + cos(angle) * 30;
  float iY = 48 + sin(angle) * 30;
  arduboy.drawLine(oX,oY,iX,iY);
}

bool Scanner::hitTarget(){
  
  return abs(targetAngle - pingAngle) < targetAperture;
}

void Scanner::placeTarget(){
  targetAngle = (PI * (7.0/6.0)) + (random(0,100)/100.0 * (2.0 * PI)/3.0);
  targetAperture = random(1,20)/100.0 + 0.1;
}

