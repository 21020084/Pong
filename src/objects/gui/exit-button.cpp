#include "exit-button.h"
#include "../../Game.h"

namespace pong {
  ExitButton::ExitButton(std::string textureFilename, GameDataRef _data) : VisibleObject(textureFilename, _data) {
    this->loadTexture(textureFilename);
  }
  ///////////////////
  ///    TODO:   ////  
  ///////////////////
  void ExitButton::handleInput(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
      int x = event.mouseButton.x;
      int y = event.mouseButton.y;
      if (this->getBoundingBox().contains(x, y)) {
        //////////////////////////////////////
        /// TODO: related to STATE MANAGER ///
        //////////////////////////////////////
        this->data->window.close();
      }
    }
  }
}