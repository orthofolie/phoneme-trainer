#include "sound.hpp"

Sound::Sound() {
  this->sound = NULL;
}

Sound::~Sound() {
  Mix_FreeMusic(this->sound);
}

void Sound::init() {
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
    printf("Erreur lors de l'initialisation du son: %s", Mix_GetError());
  }
}

void Sound::load(string nomFichier) {

  this->sound = Mix_LoadMUS(nomFichier.data());

  if (this->sound == NULL) {
    fprintf(stderr, "Impossible de charger le son : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}
