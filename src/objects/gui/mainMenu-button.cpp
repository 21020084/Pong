#include "mainMenu-button.h"
#include "../../Game.h"

namespace pong {
  MainMenuButton::MainMenuButton(GameDataRef _data) : VisibleObject("assets/menu-btn.png", _data) {}

  void MainMenuButton::handleInput(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
      int x = event.mouseButton.x;
      int y = event.mouseButton.y;
      if (this->getBoundingBox().contains(x, y)) {
        this->data->stateManager.closeCurrentState();
        this->data->stateManager.switchTo(Menu);
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