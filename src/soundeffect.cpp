#include "soundeffect.hpp"

Soundeffect::Soundeffect() {
  Sound();
}

void Soundeffect::play() {

  if (Mix_PlayMusic(this->sound, 1) == -1) {
    printf("Soundeffect::play: %s\n", Mix_GetError());
  }
}
