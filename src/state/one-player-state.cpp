#include "one-player-state.h"
#include "../objects/visible-object.h"
#include "../objects/entities/field.h"
#include "../objects/entities/ball.h"
#include "../objects/entities/player.h"
#include "../Game.h"

namespace pong {
  OnePlayerState::OnePlayerState(GameDataRef _data) : GameState(_data) {}

  int OnePlayerState::init() {
    this->data->visibleObjectManager.clearObjects();

    Field *field = new Field(Game::data);
    field->setPosition(0, 0);
    this->data->visibleObjectManager.addObject("onePlayer", field);

    return 0;
  }

  void OnePlayerState::handleInput() {
    sf::Event event;
    while (this->data->window.pollEvent(event)) {
      if (event.type == sf::Event::Closed | sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->data->window.close();
      }
    }
  }

  void OnePlayerState::update(float timeElapsed) {
  }

  void OnePlayerState::render() {
    this->data->window.clear(sf::Color::White);
    this->data->visibleObjectManager.draw();
    this->data->window.display();
  }
}