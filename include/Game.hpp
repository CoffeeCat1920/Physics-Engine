#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game {

private:

  bool isRunning;

  SDL_Window *window;
  SDL_Renderer* renderer;

public:

  Game();
  ~Game(); 

  void Init ( const char* title, int width, int height, bool fullScreen );
  void Events();
  void Update();
  void Render();
  void Clean();

  bool IsRunning();

};
