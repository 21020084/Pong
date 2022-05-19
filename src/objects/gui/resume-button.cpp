#include "resume-button.h"
#include "../../Game.h"

namespace pong {
  ResumeButton::ResumeButton(GameDataRef _data) : VisibleObject("assets/resume-btn.png", _data) {}

  void ResumeButton::handleInput(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
      int x = event.mouseButton.x;
      int y = event.mouseButton.y;
      if (this->getBoundingBox().contains(x, y)) {
        this->data->stateManager.closeCurrentState();
        return;
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