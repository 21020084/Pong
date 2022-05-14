#include "one-player-button.h"
#include "../../Game.h"

namespace pong {
  OnePlayerButton::OnePlayerButton(GameDataRef _data) : VisibleObject("assets/single_player.png", _data) {}

  void OnePlayerButton::handleInput(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
      int x = event.mouseButton.x;
      int y = event.mouseButton.y;
      if (this->getBoundingBox().contains(x, y)) {
        this->data->stateManager.addState(OnePlayer);
      }
    }
    
    auto mouse = sf::Mouse::getPosition(this->data->window);
    int x = mouse.x;
    int y = mouse.y;
    if (this->getBoundingBox().contains(x, y)) {
      this->CursorType = sf::Cursor::Hand;
    } 
  }
}