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

Titlescreen titlescreen = Titlescreen(arduboy);
Menu menu = Menu(arduboy);
Hacker hacker = Hacker(arduboy);
Success success = Success(arduboy);
Error error = Error(arduboy);
Scanner scanner = Scanner(arduboy);
Router router = Router(arduboy);

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

  Sprites::drawSelfMasked(2,2,sprite_corner,0);
  
  switch (mode){
    case Shared::title:
      mode = titlescreen.loop();
    break;
    case Shared::menu:
      mode = menu.loop();
    case Shared::hacker:
      mode = hacker.loop();
    break;
    case Shared::success:
      mode = success.loop();
    break;
    case Shared::error:
      mode = error.loop();
    break;
    case Shared::scanner:
      mode = scanner.loop();
    case Shared::router:
      mode = router.loop();
    break;
  }

  arduboy.display();
  arduboy.idle();
}
