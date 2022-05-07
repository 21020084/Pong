#include "Game-state.h"

namespace pong {
  bool GameState::hasEntered() {
    return this->m_hasEntered;
  }

  bool GameState::hasClosed() {
    return this->m_hasClosed;
  }

  void GameState::enter() {
    this->m_hasEntered = true;
  }

  void GameState::setNewState() {
    this->m_hasEntered = false;
    this->m_hasClosed = false;
  }
}