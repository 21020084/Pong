#include "Game.h"

namespace pong {
  Game::Game(const int width, const int height, const std::string title) {
    this->data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    this->data->window.setFramerateLimit(60);

    this->run();
  }

  GameDataRef Game::data = std::make_shared<GameData>();

  void Game::run() {
    float newTime, frameTime, interpolation;
    float currentTime = data->clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    /// Start the game with the splash screen.
    this->data->stateManager.addState(SplashScreen);

    /// The main game loop
    while (this->data->window.isOpen()) {
      if (this->data->stateManager.processStateChange() < 0) {
        this->data->window.close();
        break;
      }

      newTime = this->data->clock.getElapsedTime().asSeconds();
      frameTime = newTime - currentTime;

      if (frameTime > 0.25f) {
        frameTime = 0.25f;
      }

      currentTime = newTime;
      accumulator += frameTime;

      while (accumulator >= dt) {
        this->data->stateManager.handleInput();
        this->data->stateManager.update(dt);
        accumulator -= dt;
      }

      interpolation = accumulator / dt;
      this->data->stateManager.render(interpolation);
    }
  }
}