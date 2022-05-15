#include "../Game.h"
#include "state-manager.h"
#include "splashScreen-state.h"
#include "Menu-state.h"
#include "one-player-state.h"
#include "two-player-state.h"

namespace pong {
  StateManager::StateManager() {
    this->newStateID = SplashScreen;
  }

  void StateManager::init() {
    this->addState(SplashScreen);
  }

  int StateManager::processStateChange() {
    if (!this->states.empty() && this->states.top()->hasClosed()) {
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

  void StateManager::addState(StateID stateID) {
    switch (stateID) {
      case SplashScreen:
        this->newState = new SplashScreenState(Game::data);
        break;

      case Menu:
        if (this->newStateID == Menu) {
          break;
        }
        this->newState = new MenuState(Game::data);
        break;

      case OnePlayer:
        this->newState = new OnePlayerState(Game::data);
        break;

      case TwoPlayer:
        this->newState = new TwoPlayerState(Game::data);
        break;
        
      case GameOver:
        // this->newState = new GameOverState();
        break;
    }
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
