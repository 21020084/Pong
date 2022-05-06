#include "state-manager.h"

namespace pong {
  int StateManager::changeState() {
    if (this->states.empty()) {
      return -1;
    }

    if (currentState->hasExited()) {
      this->states.pop();
      delete currentState;
      currentState = this->states.top();
    }

    int Init = this->currentState->init();
    return Init;
  }

  void StateManager::addState(GameState *state) {
    this->states.push(state);
  }

  void StateManager::handleInput() {
    if (currentState->hasExited()) return;
    this->currentState->handleInput();
  }

  void StateManager::update(float elapsedTime) {
    if (currentState->hasExited()) return;
    this->currentState->update(elapsedTime);
  }

  void StateManager::render(float interpolation) {
    if (currentState->hasExited()) return;
    this->currentState->render();
  }

} // namespace pong
