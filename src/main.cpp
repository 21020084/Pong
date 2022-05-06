#include "main.h"

int main()
{
  freopen("log.txt", "w", stdout) ;
  srand(time(nullptr));
  pong::Game(800, 600, "Pong");  
  return 0;
}