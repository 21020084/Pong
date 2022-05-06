#ifndef STATE_STATE_MANAGER_H
#define STATE_STATE_MANAGER_H

#include "Game-state.h"
#include <stack>

namespace pong {
  class StateManager {
    public:
      StateManager() = default;
      ~StateManager() = default;
      int changeState();
      void addState(GameState *state);
      void handleInput();
      void update(float elapsedTime);
      void render(float interpolation);
      // bool empty();
    private:
      std::stack<GameState *> states;
      GameState *currentState = nullptr;
  };
}
 
#endif /// STATE_STATE_MANAGER_H