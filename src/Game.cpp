#include "Game.h"
#include "DEFINITION.h"

namespace pong {
  GameDataRef Game::data = std::make_shared<GameData>();

  void Game::run() {
    data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong", sf::Style::Close | sf::Style::Resize);
    data->window.setFramerateLimit(FPS);

    float newTime, frameTime, interpolation;
    float currentTime = data->clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    /// Start the game with the splash screen.
    data->stateManager.init();

    /// The main game loop
    while (data->window.isOpen()) {
      if (data->stateManager.processStateChange() < 0) {
        data->window.close();
        break;
      }

      newTime = data->clock.getElapsedTime().asSeconds();
      frameTime = newTime - currentTime;

      if (frameTime > 0.25f) {
        frameTime = 0.25f;
      }

      currentTime = newTime;
      accumulator += frameTime;

      while (accumulator >= dt) {
        data->stateManager.handleInput();
        if (!data->window.isOpen()) {
          break;
        }
        data->stateManager.update(dt);
        accumulator -= dt;
      }

      data->stateManager.render();
    }
  }
}