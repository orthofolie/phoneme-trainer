#include "music.hpp"

Music::Music() {
  Sound();
}

void Music::play() {

  if (Mix_PlayMusic(this->sound, -1) == -1) {
    printf("Music::play: %s\n", Mix_GetError());
  }
}
