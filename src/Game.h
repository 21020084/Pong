#ifndef TRY_BASE_H
#define TRY_BASE_H

#include <string>
#include <memory>
#include "state/state-manager.h"
#include "objects/visible-object-manager.h"

namespace pong {
  struct GameData {
    sf::RenderWindow window;
    sf::Clock clock; 
    StateManager stateManager;
    VisibleObjectManager visibleObjectManager;
  };

  typedef std::shared_ptr<GameData> GameDataRef;
  
  class Game {
    public:
      static GameDataRef data;
      static void run();

    private:
      static constexpr int SCREEN_HEIGHT = 940;
      static constexpr int SCREEN_WIDTH = 1406;
      static std::string SCREEN_TITLE;
      // Updates run at 60 per second.
		  static constexpr float dt = 1.0f / 60.0f;
      static sf::Clock clock;
  };
}

#endif /// TRY_BASE_H