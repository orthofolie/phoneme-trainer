#ifndef SOUND_HPP
#define SOUND_HPP

using namespace std;

#include <SDL/SDL_mixer.h>
#include <iostream>

class Sound {

  public:
    Sound();
    ~Sound();
    void init();
    void load(string nomFichier);

  protected:
    Mix_Music* sound;

};

#endif
