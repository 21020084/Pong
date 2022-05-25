#include "../Game.h"
#include "state-manager.h"
#include "splashScreen-state.h"
#include "Menu-state.h"
#include "one-player-state.h"
#include "two-player-state.h"
#include "pause-state.h"

namespace pong {
  StateManager::StateManager() {
    this->togoStateID = None;
  }

  StateID StateManager::toGoStateID() {
    return this->togoStateID;
  }

  void StateManager::init() {
    this->addState(SplashScreen);
  }

  //////////////////////////////////////////////////////////////////////////////
  int StateManager::processStateChange() {
    while ((this->togoStateID != None) && (!this->states.empty()) && (this->states.top()->getID() != this->togoStateID)) {
      delete this->states.top();
      this->states.pop();
    }
    this->togoStateID = None;

    if (!this->states.empty() && this->states.top()->removed()) {
      // this->states.top()->exiting();
      delete this->states.top();
      this->states.pop();
    }

    if (this->newState != nullptr) {
      if (this->newState->init() != 0) {
        return -1;
      }
      this->newState->add();
      // this->newState->entering();
      this->states.push(this->newState);
      this->newState = nullptr;
    }

    this->states.top()->entering();

    return 0;
  }
  //////////////////////////////////////////////////////////////////////////////

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
        
      case Pause:
        this->newState = new PauseState(Game::data);
        break;
    }
    this->newState->setNewState();
  }

  void StateManager::switchTo(StateID stateID) {
    this->togoStateID = stateID;
  }
  
  void StateManager::removeCurrentState() {
    this->states.top()->exiting();
    this->states.top()->remove();
  }

  void StateManager::exitCurrentState() {
    this->states.top()->exiting();
  }

  void StateManager::clearToGoState() {
    this->togoStateID = None;
  }

  void StateManager::handleInput() {
    this->states.top()->handleInput();
  }

  void StateManager::update(float elapsedTime) {
    this->states.top()->update(elapsedTime);
  }

  void StateManager::render() {
    this->states.top()->render();
  }

} // namespace pong
