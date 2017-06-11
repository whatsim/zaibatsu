#include <Arduboy2.h>
#include "Shared.h"
#include "Assets.h"

// modes
#include "Titlescreen.h"
#include "Menu.h"
#include "Hacker.h"
#include "Success.h"
#include "Error.h"




// Make an instance of arduboy used for many functions
Arduboy2 arduboy;

Titlescreen titlescreen = Titlescreen(arduboy);
Menu menu = Menu(arduboy);
Hacker hacker = Hacker(arduboy);
Success success = Success(arduboy);
Error error = Error(arduboy);

Shared::Gamemode mode = Shared::title;

#define X_MID (WIDTH / 2)
#define Y_MID (HEIGHT /2)

// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  
  //initiate arduboy instance
  
  arduboy.boot(); // raw hardware
  arduboy.blank(); // blank the display

  Sprites::drawSelfMasked(2,2,sprite_corner,0);
  // check for and handle buttons held during start up for system control
  arduboy.audio.begin();

  // here we set the framerate to 30, we do not need to run at default 60 and
  // it saves us battery life.
  arduboy.setFrameRate(30);

}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  arduboy.clear();
  
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
  }

  arduboy.display();
}
