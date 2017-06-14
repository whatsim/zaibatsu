#include <Arduboy2.h>
#include <ArduboyTones.h>

#include "Shared.h"
#include "Assets.h"

// modes
#include "Titlescreen.h"
#include "Menu.h"
#include "Hacker.h"
#include "Success.h"
#include "Error.h"
#include "Scanner.h"
#include "Router.h"
#include "Dice.h"

// Make an instance of arduboy used for many functions
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

Titlescreen titlescreen = Titlescreen();
Menu menu = Menu();
Hacker hacker = Hacker();
Success success = Success();
Error error = Error();
Scanner scanner = Scanner();
Router router = Router();
Dice dice = Dice();

int scanlinePos = 0;
int exitTimer = 0;

Shared::Gamemode mode = Shared::title;

void setup() {
  
  //initiate arduboy instance
//  arduboy.begin();
  arduboy.boot(); // raw hardware
  arduboy.blank(); // blank the display
  arduboy.audio.begin();

  // here we set the framerate to 30, we do not need to run at default 60 and
  // it saves us battery life.
  arduboy.setFrameRate(30);

}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  if(arduboy.justReleased(A_BUTTON | B_BUTTON)){
    sound.tone(440,50);
  }

  if(arduboy.justReleased(UP_BUTTON | DOWN_BUTTON | LEFT_BUTTON | RIGHT_BUTTON)){
    sound.tone(220,50);
  }

  if(arduboy.justReleased(B_BUTTON)){
    arduboy.invert(true);
  } else {
    arduboy.invert(false);
  }
  
  arduboy.clear();
  arduboy.pollButtons();

  switch (mode){
    case Shared::title:
      mode = titlescreen.loop(arduboy);
    break;
    case Shared::menu:
      mode = menu.loop(arduboy);
    break;
    case Shared::hacker:
      mode = hacker.loop(arduboy, sound);
    break;
    case Shared::success:
      mode = success.loop(arduboy, sound);
    break;
    case Shared::error:
      mode = error.loop(arduboy, sound);
    break;
    case Shared::scanner:
      mode = scanner.loop(arduboy);
    break;
    case Shared::router:
      mode = router.loop(arduboy);
    break;
    case Shared::dice:
      mode = dice.loop(arduboy);
    break;
  }

  if(arduboy.everyXFrames(5)){
    if (arduboy.pressed(A_BUTTON)){
      // hold b to quit to menu
      exitTimer ++;
      if(exitTimer == 5) {
        arduboy.initRandomSeed();
        if(mode == Shared::menu){
          mode = Shared::dice;
        } else {
          mode = Shared::menu;
          hacker.hasPuzzle = false;
          scanner.isSetup = false;
          router.isSetup = false;
          dice.result = 0;
        }
        sound.tone(110,100);
      }
    } else if(!arduboy.pressed(A_BUTTON)){
      exitTimer = 0;
    }
  }

  scanlinePos ++;
  scanlinePos %= 64;
  arduboy.drawFastHLine(0,scanlinePos,WIDTH, BLACK);
  Sprites::drawSelfMasked(2,2,sprite_corner,0);
  arduboy.display();
  arduboy.idle();
}
