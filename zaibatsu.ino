#include <Arduboy2.h>
#include "Shared.h"
#include "Titlescreen.h"
#include "Menu.h"

// Make an instance of arduboy used for many functions
Arduboy2 arduboy;

Titlescreen titlescreen = Titlescreen(arduboy);
Menu menu = Menu(arduboy);

Shared::Gamemode mode = Shared::title;

#define X_MID (WIDTH / 2)
#define Y_MID (HEIGHT /2)

// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  
  //initiate arduboy instance
  
  arduboy.boot(); // raw hardware
  arduboy.blank(); // blank the display

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
    break;
  }

  arduboy.display();
}
