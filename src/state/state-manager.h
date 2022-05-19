#ifndef STATE_STATE_MANAGER_H
#define STATE_STATE_MANAGER_H

#include <stack>
#include "Game-state.h"

namespace pong {
  
  class StateManager {
    public:
      StateManager();
      ~StateManager() = default;
      StateID toGoStateID();

      void init();
      int processStateChange();
      void addState(StateID stateID);
      void switchTo(StateID stateID);
      void closeCurrentState();
      void clearToGoState();
      void handleInput();
      void update(float elapsedTime);
      void render();
      
    private:
      std::stack<GameState *> states;
      GameState *newState;
      StateID newStateID;
      StateID togoStateID;
  };
}
 
#endif /// STATE_STATE_MANAGER_H