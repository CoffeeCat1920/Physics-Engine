#include "./include/Game.hpp"


Game *game = nullptr;

int main (int argc, char *argv[]) {

  const int FPS = 60;
  const int FRAMEDELAY = 1000/FPS;

  game = new Game();

  game->Init( "Title" , 64 * 3, 64 * 3, false);

  while ( game->IsRunning() ) {
    
    game->Events();
    game->Update();
    game->Render();

  }

  game->Clean();

  delete game;
  
  return 0;
}
