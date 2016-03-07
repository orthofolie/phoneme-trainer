#include "events.hpp"

Events::Events() {
  this->init();
}

bool Events::askQuit() {

  bool askQuit = false;

  if (this->key[SDLK_ESCAPE] == 1) {
    askQuit = true;
  } else if (this->quit == 1) {
    askQuit = true;
  }

  return askQuit;
}

void Events::init() {
  SDL_EnableKeyRepeat(1,0);
}

void Events::update() {

  SDL_Event event;

  this->mouse_buttons[SDL_BUTTON_WHEELUP] = 0;
  this->mouse_buttons[SDL_BUTTON_WHEELDOWN] = 0;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN:
        this->key[event.key.keysym.sym] = 1;
        break;
      case SDL_KEYUP:
        this->key[event.key.keysym.sym] = 0;
        break;
      case SDL_MOUSEMOTION:
        this->mouse.x = event.motion.x;
        this->mouse.y = event.motion.y;
        this->mouse_rel.x = event.motion.xrel;
        this->mouse_rel.y = event.motion.yrel;
        break;
      case SDL_MOUSEBUTTONDOWN:
        this->mouse_buttons[event.button.button] = 1;
        break;
      case SDL_MOUSEBUTTONUP:
        if (event.button.button != SDL_BUTTON_WHEELUP && event.button.button != SDL_BUTTON_WHEELDOWN) {
          this->mouse_buttons[event.button.button] = 0;
        }
        break;
      case SDL_QUIT:
        this->quit = 1;
        break;
      case SDLK_ESCAPE:
        this->key[SDLK_ESCAPE] = 1;
      default:
        break;
    }
  }
}
