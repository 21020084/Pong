#include "splashScreen-state.h"

namespace pong {
  SplashScreenState::SplashScreenState(GameDataRef _data) : data(_data) {}

  int SplashScreenState::init() {
    sf::Texture texture;
    if (!texture.loadFromFile(SPLASH_SCENE_BACKGROUND_FILEPATH)) {
      std::cout << "Error loading splashScreen.png" << std::endl;
      return - 1;
    }
    this->sprite.setTexture(texture);
    return 0;
  }

  void SplashScreenState::handleInput() {
    /// Check if the user want to quit the game
    sf::Event event;
    while (data->window.pollEvent(event)) {
      /// If the user wants to quit the game
      if (event.type == sf::Event::Closed ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->m_hasClosed  = true;
        this->data->window.close();
      }
    }
  }

  void SplashScreenState::update(float timeElapsed) {
    if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
      this->data->stateManager.addState(Menu);
      this->m_hasClosed = true;
    } else {
      this->sprite.setColor(sf::Color(255, 255, 255,
                            255 - (this->clock.getElapsedTime().asSeconds() * 255 / SPLASH_STATE_SHOW_TIME)));
    }
  }

  void SplashScreenState::render() {
    this->data->window.draw(this->sprite);
    this->data->window.display();
  }
}