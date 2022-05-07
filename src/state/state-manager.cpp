#include "state-manager.h"

namespace pong {
  int StateManager::processStateChange() {
    if (this->states.empty()) {
      return -1;
    }
    if (this->states.top()->hasClosed()) {
      delete this->states.top();
      this->states.pop();
    }
    if (!this->newState->hasEntered()) {
      if (this->newState->init() != 0) {
        return -1;
      }
      this->newState->enter();
      this->states.push(this->newState);
    }
    return 0;
  }

  void StateManager::addState(GameState *state) {
    this->newState = state;
    this->newState->setNewState();
  }

  void StateManager::handleInput() {
    this->states.top()->handleInput();
  }

  void StateManager::update(float elapsedTime) {
    this->states.top()->update(elapsedTime);
  }

  void StateManager::render(float interpolation) {
    this->states.top()->render();
  }

} // namespace pong
