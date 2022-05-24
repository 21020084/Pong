#include "splashScreen-state.h"
#include "../Game.h"

namespace pong {
  SplashScreenState::SplashScreenState(GameDataRef _data) : GameState(_data) {
    this->m_ID = SplashScreen;
  }

  int SplashScreenState::init() {
    if (!this->texture.loadFromFile(SPLASH_SCENE_BACKGROUND_FILEPATH)) {
      std::cout << "Error loading splashScreen.png" << std::endl;
      return - 1;
    }
    this->sprite.setTexture(this->texture);
    return 0;
  }

  void SplashScreenState::handleInput() {
    /// Check if the user want to quit the game
    sf::Event event;
    while (this->data->window.pollEvent(event)) {
      /// If the user wants to quit the game
      if (event.type == sf::Event::Closed ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->m_removed  = true;
        this->data->window.close();
      }
    }
  }

  void SplashScreenState::update(float timeElapsed) {
    /// Fade in the splash screen
    if (this->clock.getElapsedTime().asSeconds() <= SPLASH_STATE_SHOW_TIME) {
      this->sprite.setColor(sf::Color(255, 255, 255,
                            255 * this->clock.getElapsedTime().asSeconds() / SPLASH_STATE_SHOW_TIME));
      return;
    };
    /// Fade out the splash screen
    if (this->clock.getElapsedTime().asSeconds() <= SPLASH_STATE_SHOW_TIME + SPLASH_STATE_SHOW_TIME) {
      this->sprite.setColor(sf::Color(255, 255, 255,
                            255 * (1 - this->clock.getElapsedTime().asSeconds() / SPLASH_STATE_SHOW_TIME)));
      return;
    }
    /// Switch to the next state
    this->data->stateManager.addState(Menu);
    this->m_removed = true;
  }

  void SplashScreenState::render() {
    this->data->window.clear(sf::Color::White);
    this->data->window.draw(this->sprite);
    this->data->window.display();
  }
} 