#ifndef STATE_STATE_MANAGER_H
#define STATE_STATE_MANAGER_H

#include "Game-state.h"
#include <stack>

namespace pong {
  class StateManager {
    public:
      StateManager();
      ~StateManager() = default;
      int processStateChange();
      void addState(StateID stateID);
      void handleInput();
      void update(float elapsedTime);
      void render(float interpolation);
      // bool empty();
    private:
      std::stack<GameState *> states;
      GameState *newState;
      StateID newStateID;
  };
}
 
#endif /// STATE_STATE_MANAGER_H