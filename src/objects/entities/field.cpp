#include "field.h"
#include "../../Game.h"

namespace pong {
  Field::Field(std::string textureFilename, GameDataRef _data) : VisibleObject(textureFilename, _data) {
    this->loadTexture(textureFilename);
  }

  void Field::draw() {
    this->data->window.draw(this->sprite);
  }
}