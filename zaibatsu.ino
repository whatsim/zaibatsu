#include <Arduboy2.h>
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

// Make an instance of arduboy used for many functions
Arduboy2 arduboy;

Titlescreen titlescreen = Titlescreen();
Menu menu = Menu();
Hacker hacker = Hacker();
Success success = Success();
Error error = Error();
Scanner scanner = Scanner();
Router router = Router();

int scanlinePos = 0;

Shared::Gamemode mode = Shared::title;

void setup() {
  
  //initiate arduboy instance
  arduboy.begin();
//  arduboy.boot(); // raw hardware
//  arduboy.blank(); // blank the display
//  arduboy.audio.begin();

  // here we set the framerate to 30, we do not need to run at default 60 and
  // it saves us battery life.
  arduboy.setFrameRate(30);

}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  arduboy.invert(false);
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
      mode = hacker.loop(arduboy);
    break;
    case Shared::success:
      mode = success.loop(arduboy);
    break;
    case Shared::error:
      mode = error.loop(arduboy);
    break;
    case Shared::scanner:
      mode = scanner.loop(arduboy);
    break;
    case Shared::router:
      mode = router.loop(arduboy);
    break;
  }

  scanlinePos ++;
  scanlinePos %= 64;
  arduboy.drawFastHLine(0,scanlinePos,WIDTH, BLACK);
  Sprites::drawSelfMasked(2,2,sprite_corner,0);
  arduboy.display();
  arduboy.idle();
}
