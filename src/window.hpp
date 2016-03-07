#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "point.hpp"
#include "surface.hpp"

using namespace std;

class Window  : public Surface {

  public:
    Window();
    Window(string icon_location, string title);
    void init();

  private:
    string icon_location;
    string title;
};

#endif
