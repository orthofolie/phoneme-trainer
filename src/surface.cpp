#include "surface.hpp"

Surface::Surface() {
  this->surface = NULL;
}

Surface::~Surface() {
    SDL_FreeSurface(this->surface);
    this->surface = NULL;
}

Surface::Surface(Point s_origin, Point s_size) {

  this->origin = s_origin;
  this->size = s_size;
  this->surface = SDL_CreateRGBSurface(SDL_HWSURFACE, s_size.x, s_size.y, 32, 0, 0, 0, 0);

  if (this->surface == NULL) {
    Surface::error_quit(SDL_GetError());
  }
}

void Surface::add_pix(Point pix, Uint32 color) {
  if (pix.x > 0 && pix.y > 0 && pix.x < this->size.x && pix.y < this->size.y) {
    *((Uint32*) this->surface->pixels + (this->surface->h - pix.y - 1) * this->surface->w + pix.x) = color;
  }
}

void Surface::clear() {
  if (SDL_FillRect(this->surface, NULL, 0x000000) == -1) {
    Surface::error_quit(SDL_GetError());
  }
}

void Surface::error_quit(const char* error) {
  puts(error);
  SDL_Quit();
  exit(EXIT_FAILURE);
}

void Surface::load_img(const char* img_name) {

  SDL_Surface* img_result;
  SDL_Surface* img_ram;

  img_ram = IMG_Load(img_name);

  if (img_ram == NULL) {
    error_quit(SDL_GetError());
  }

  img_result = SDL_DisplayFormat(img_ram);

  if (img_result == NULL) {
    error_quit(SDL_GetError());
  }

  SDL_FreeSurface(img_ram);

  // this->surface = img_result;
}

void Surface::print() {
  if (this->surface != NULL){
    if (SDL_Flip(this->surface) == -1) {
      Surface::error_quit(SDL_GetError());
    }
  } else {
    Surface::error_quit("Error: this->surface == NULL\n");
  }
}
