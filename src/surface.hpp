#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "point.hpp"

using namespace std;

class Surface {

  public:
    Surface();
    ~Surface();
    Surface(Point origin, Point size);

  protected:
    SDL_Surface* surface;
    Point size;
    Point origin;
    void error_quit(const char* error);

  public:
    void add_pix(Point pix, Uint32 color);
    void print();
    void clear();
    void load_img(const char* img_name);
};

#endif
