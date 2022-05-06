#ifndef GAME_GAMESTATE_H
#define GAME_GAMESTATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../objects/visible-object-manager.h"

namespace pong {
  class GameState {
    public:
      GameState();
      virtual ~GameState() = default;
      virtual int init() = 0;
      virtual void handleInput() = 0;
      virtual void update(float elapsedTime) = 0;
      virtual void render() = 0;
      virtual bool hasExited() = 0;
      // virtual void endLoopLogic() {};

      // VisibleObjectManager* getObjectManager();

    protected:
      // VisibleObjectManager visibleObjectManager;
      bool m_hasExited;
  };
}

#endif /// GAME_GAMESTATE_H