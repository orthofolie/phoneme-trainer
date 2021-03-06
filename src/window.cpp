#include "window.hpp"

using namespace std;

Window::Window() {
  Surface();
  this->icon_location = "./media/img/window/icon.png";
  this->title = "Phoneme Trainer";
  this->origin.x = 0;
  this->origin.y = 0;
}

Window::Window(string w_icon_location, string w_title) {
  Surface();
  this->icon_location = w_icon_location;
  this->title = title;
  this->origin.x = 0;
  this->origin.y = 0;
}

void Window::init() {

  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetIcon(IMG_Load(this->icon_location.data()), NULL);
  SDL_WM_SetCaption(this->title.data(), NULL);

  // full screen mode
  /*
    const SDL_VideoInfo* videoInfo;
    videoInfo = SDL_GetVideoInfo();
    this->size.x = videoInfo->current_w;
    this->size.y = videoInfo->current_h;
    this->surface = SDL_SetVideoMode(this->size.x, this->size.y, 32, SDL_FULLSCREEN|SDL_DOUBLEBUF);
  */

  // window mode
    this->size.x = 800;
    this->size.y = 600;
    this->surface = SDL_SetVideoMode(this->size.x, this->size.y, 32, SDL_DOUBLEBUF|SDL_RESIZABLE);

  if (this->surface == NULL) {
    error_quit(SDL_GetError());
  }

  printf("Taille de la fenêtre ouverte: %d, %d\n", this->size.x, this->size.y);
}
