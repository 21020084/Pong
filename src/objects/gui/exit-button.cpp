#include "exit-button.h"
#include "../../Game.h"

namespace pong {
  ExitButton::ExitButton(GameDataRef _data) : VisibleObject(_data) {}

  void ExitButton::handleInput() {
    sf::Event event;
    if (event.type == sf::Event::MouseButtonPressed) {
      int x = event.mouseButton.x;
      int y = event.mouseButton.y;
      if (this->getBoundingBox().contains(x, y)) {
        this->data->window.close();
      }
    }
  }
}