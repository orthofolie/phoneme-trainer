#ifndef MUSIC_HPP
#define MUSIC_HPP

using namespace std;

#include "sound.hpp"

class Music : public Sound {

  public:
    Music();
    void play();
};

#endif
