#include <iostream>
#include "../Game.h"
#include "visible-object.h"

namespace pong {
  sf::Cursor::Type VisibleObject::currentCursorType = sf::Cursor::Arrow;
  sf::Cursor::Type VisibleObject::previousCursorType = sf::Cursor::Arrow;

  VisibleObject::VisibleObject(std::string textureFilename, GameDataRef _data) : data(_data) {
    this->loadTexture(textureFilename);
  };

  VisibleObject::VisibleObject(std::string textureFilename) {
    this->loadTexture(textureFilename);
  }

  void VisibleObject::loadTexture(std::string textureFilename) {
    this->isLoaded = false;
    if (!this->texture.loadFromFile(textureFilename)) {
      std::cout << "Error loading texture: " << textureFilename << std::endl;
      return;
    } 
    this->isLoaded = true;
    this->sprite.setTexture(this->texture);
  }

  void VisibleObject::draw() {
    if (!this->isLoaded) return;
    this->data->window.draw(this->sprite);
  }

  void VisibleObject::move(float x, float y) {
    if (!this->isLoaded) return;
    this->sprite.move(x, y);
  }

  void VisibleObject::setPosition(float x, float y) {
    if (!this->isLoaded) return;
    this->sprite.setPosition(x, y);
  }

  sf::Vector2f VisibleObject::getPosition() {
    if (!this->isLoaded) return sf::Vector2f(0, 0);
    return this->sprite.getPosition();
  }

  sf::FloatRect VisibleObject::getBoundingBox() {
    return this->sprite.getGlobalBounds();
  }

  float VisibleObject::getTop() {
    sf::FloatRect boundingRect = getBoundingBox();
    return boundingRect.top;
  }

  float VisibleObject::getBottom() {
    sf::FloatRect boundingRect = getBoundingBox();
    return boundingRect.top + boundingRect.height;
  }

  float VisibleObject::getLeft() {
    sf::FloatRect boundingRect = getBoundingBox();
    return boundingRect.left;
  }

  float VisibleObject::getRight() {
    sf::FloatRect boundingRect = getBoundingBox();
    return boundingRect.left + boundingRect.width;
  }
}