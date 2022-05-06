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
    // VisibleObjectManager visibleObjectManager;
  };

  typedef std::shared_ptr<GameData> GameDataRef;
  
  class Game {
    public:
      Game(const int width, const int height, const std::string title);
      void run();

    private:
      GameDataRef data = std::make_shared<GameData>();
      // Updates run at 60 per second.
		  static constexpr float dt = 1.0f / 60.0f;
      static sf::Clock clock;
  };
}

#endif /// TRY_BASE_H