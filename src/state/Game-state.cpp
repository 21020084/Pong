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

  bool GameState::added() {
    return this->m_added;
  }

  bool GameState::removed() {
    return this->m_removed;
  }

  void GameState::add() {
    this->m_added = true;
  }

  void GameState::entering() {
    if (this->m_entered) {
      return;
    }
    if (this->m_ID == SplashScreen) return;
    this->clock.restart();
    
    while (this->clock.getElapsedTime().asSeconds() <= TRANSITION_TIME) {
      this->transitionSprite.setColor(sf::Color(255, 255, 255,
                            255 * (1 - this->clock.getElapsedTime().asSeconds() / TRANSITION_TIME)));
      this->render();
    };
    this->m_entered = true;
  }

  void GameState::remove() {
    this->m_removed = true;
  }

  void GameState::exiting() {
    if (this->m_ID == SplashScreen) return;
    this->clock.restart();

    while (this->clock.getElapsedTime().asSeconds() <= TRANSITION_TIME) {
      this->transitionSprite.setColor(sf::Color(255, 255, 255,
                            255 * this->clock.getElapsedTime().asSeconds() / TRANSITION_TIME));
      this->render();
    };
    this->m_entered = false;
  }

  void GameState::setNewState() {
    this->m_added = false;
    this->m_removed = false;
    this->m_entered = false;
  }
}