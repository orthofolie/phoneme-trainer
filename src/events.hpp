#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SDL/SDL.h>
#include "point.hpp"

using namespace std;

class Events {

  public:
    Events();
    bool askQuit();
    void update();

  private:
    char key[SDLK_LAST];
    Point mouse;
    Point mouse_rel;
    char mouse_buttons[8];
    char quit;
    void init();

};

#endif
