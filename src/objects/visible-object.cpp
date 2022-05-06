#include "visible-object.h"

namespace pong {
  VisibleObject::VisibleObject(std::string textureFilename) {
    isLoaded = false;
    if (!texture.loadFromFile(textureFilename)) {
      std::cout << "Error loading texture: " << textureFilename << std::endl;
    } else {
      isLoaded = true;
    }
    sprite.setTexture(texture);
  }

  VisibleObject::~VisibleObject() {
    // std::cout << "Destroying VisibleObject" << std::endl;
  }

  void VisibleObject::draw(sf::RenderWindow &window) {
    if (!this->isLoaded) return;
    window.draw(sprite);
  }

  void VisibleObject::move(float x, float y) {
    if (!this->isLoaded) return;
    sprite.move(x, y);
  }

  void VisibleObject::setPosition(float x, float y) {
    if (!this->isLoaded) return;
    sprite.setPosition(x, y);
  }

  sf::Vector2f VisibleObject::getPosition() {
    if (!this->isLoaded) return sf::Vector2f(0, 0);
    return sprite.getPosition();
  }

  sf::Rect<float> VisibleObject::getBoundingBox() {
    return sprite.getGlobalBounds();
  }

  float VisibleObject::getTop() {
    sf::Rect<float> boundingRect = getBoundingBox();
    return boundingRect.top;
  }

  float VisibleObject::getBottom() {
    sf::Rect<float> boundingRect = getBoundingBox();
    return boundingRect.top + boundingRect.height;
  }

  float VisibleObject::getLeft() {
    sf::Rect<float> boundingRect = getBoundingBox();
    return boundingRect.left;
  }

  float VisibleObject::getRight() {
    sf::Rect<float> boundingRect = getBoundingBox();
    return boundingRect.left + boundingRect.width;
  }
}