#include "../include/Game.hpp"
#include <iostream>

Game::Game() {

}

Game::~Game() {

  SDL_DestroyWindow( window );
  SDL_DestroyRenderer( renderer );
  SDL_Quit();
  std::cout << "DEBUG: Game is Cleaned" << std::endl;

}

void Game::Init ( const char* title, int width, int height, bool fullScreen ) {

  int flags;

  fullScreen ? flags = SDL_WINDOW_FULLSCREEN : flags = 0;

  if ( SDL_Init( SDL_INIT_EVERYTHING ) == 0 ) {
    
    std::cout << "DEBUG: SDL Initialized Everything " << std::endl;

    this->window = SDL_CreateWindow( title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags );

    if ( window ) {
      
      std::cout << "DEBUG: Window Made " << std::endl;

    }

    this->renderer = SDL_CreateRenderer( this->window, -1, 0);

    if ( renderer ) {

      SDL_SetRenderDrawColor( renderer , 255, 255, 255, 255);

      std::cout << "DEBUG: Renderer Made " << std::endl;

    }

    this->isRunning = true;

  }
  else {
    
    std::cerr << "ERROR: DEBUG SDL didn't Initialized " << std::endl;

    this->isRunning = false;

  }

}

void Game::Events() {

  SDL_Event event;
  SDL_PollEvent( &event );

  switch ( event.type ) {

    case SDL_QUIT:
    this->isRunning = false;
    break;
    default:
    break;
    
  }

}

void Game::Update() {

}

void Game::Render() {

  SDL_RenderClear( this->renderer );

  // Game Object here
  SDL_RenderPresent( renderer );

}

void Game::Clean() {


}

bool Game::IsRunning() {

  return isRunning;

}
