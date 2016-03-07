#include "main.hpp"

int main() {

  Events input;
  Window window;
  Soundeffect sound;

  window.init();
  sound.init();

  while(!input.askQuit()){
    input.update();
    window.clear();
    //sound.load("media/sound/soundseffect/sound.ogg");
    //sound.play();
    window.print();
  }

  Mix_CloseAudio();
  // SDL_Quit();

  return EXIT_SUCCESS;
}
