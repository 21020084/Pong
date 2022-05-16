#ifndef STATE_STATE_MANAGER_H
#define STATE_STATE_MANAGER_H

#include <stack>
#include "Game-state.h"

namespace pong {
  
  class StateManager {
    public:
      StateManager();
      ~StateManager() = default;
      void init();
      int processStateChange();
      void addState(StateID stateID);
      void handleInput();
      void update(float elapsedTime);
      void render(float interpolation);
    private:
      std::stack<GameState *> states;
      GameState *newState;
      StateID newStateID;
  };
}
 
#endif /// STATE_STATE_MANAGER_H