#include "two-player-button.h"
#include "../../Game.h"

namespace pong {
  TwoPlayerButton::TwoPlayerButton(GameDataRef _data) : VisibleObject("assets/PvP.png", _data) {}

  void TwoPlayerButton::handleInput(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
      int x = event.mouseButton.x;
      int y = event.mouseButton.y;
      if (this->getBoundingBox().contains(x, y)) {
        this->data->stateManager.addState(TwoPlayer);
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