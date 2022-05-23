#include "Game-state.h"
#include "../DEFINITION.h"
#include "../Game.h"

namespace pong {
  GameState::GameState(GameDataRef _data) : data(_data) {
    this->transitionTexture.loadFromFile("assets/field.png");
    this->transitionSprite.setTexture(this->transitionTexture);
  }

  StateID GameState::getID() {
    return this->m_ID;
  }

  bool GameState::hasEntered() {
    return this->m_hasEntered;
  }

  bool GameState::hasClosed() {
    return this->m_hasClosed;
  }

  void GameState::enter() {
    this->m_hasEntered = true;
    if (this->m_ID == SplashScreen) return;
    this->clock.restart();
    
    while (this->clock.getElapsedTime().asSeconds() <= TRANSITION_TIME) {
      this->transitionSprite.setColor(sf::Color(255, 255, 255,
                            255 * (1 - this->clock.getElapsedTime().asSeconds() / TRANSITION_TIME)));
      this->render();
    };
  }

  void GameState::close() {
    this->m_hasClosed = true;
    if (this->m_ID == SplashScreen) return;
    this->clock.restart();

    while (this->clock.getElapsedTime().asSeconds() <= TRANSITION_TIME) {
      this->transitionSprite.setColor(sf::Color(255, 255, 255,
                            255 * this->clock.getElapsedTime().asSeconds() / TRANSITION_TIME));
      this->render();
    };
  }

  void GameState::setNewState() {
    this->m_hasEntered = false;
    this->m_hasClosed = false;
  }
}