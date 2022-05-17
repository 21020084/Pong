#include "Game.h"

int main()
{
  freopen("log.txt", "w", stdout) ;
  srand(time(nullptr));
  pong::Game::run();
  return 0;
}