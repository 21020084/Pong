#include "visible-object-manager.h"
#include "entities/ball.h"

namespace pong {

  VisibleObjectManager::~VisibleObjectManager() {
    auto itr = this->objects.begin();
    while (itr != this->objects.end()) {
      delete itr->second;
      ++itr;
    }
  }

  void VisibleObjectManager::addObject(std::string name, VisibleObject *object) {
    this->objects.insert(std::pair<std::string, VisibleObject *>(name, object));
  }

  void VisibleObjectManager::removeObject(std::string name) {
    auto results = this->objects.find(name);
    if (results != this->objects.end()) {
      delete results->second;
      this->objects.erase(results);
    }
  }

  void VisibleObjectManager::clearObjects() {
    auto itr = this->objects.begin();
    while (itr != this->objects.end()) {
      delete itr->second;
      ++itr;
    }
    this->objects.clear();
  }

  VisibleObject *VisibleObjectManager::getObject(std::string name) {
    auto results = this->objects.find(name);
    if (results == this->objects.end()) {
      return nullptr;
    }
    return results->second;
  }

  void VisibleObjectManager::handleInput(sf::Event &event, char stateSignal) {
    auto itr = this->objects.begin();
    while (itr != this->objects.end()) {
      if (itr->first[0] == stateSignal) {
        itr->second->handleInput(event);
      }
      ++itr;
    }
  }

  void VisibleObjectManager::update(float timeElapsed, char stateSignal) {
    auto itr = this->objects.begin();
    while (itr != this->objects.end()) {
      if (itr->first[0] == stateSignal) {
        itr->second->update(timeElapsed);
      }
      ++itr;
    }

    /// Process collision between objects.  
    auto originItr = this->objects.begin();
    while (originItr != this->objects.end()) {
      sf::FloatRect originBound = originItr->second->getBoundingBox();

      auto targetItr = this->objects.begin();

      while (targetItr != this->objects.end()) {
        if (targetItr == originItr) {
          ++targetItr;
          continue;
        }
        sf::FloatRect targetBound = targetItr->second->getBoundingBox();
        if (originBound.intersects(targetBound)) {
          originItr->second->collideWith(targetItr->second);
        }
        ++targetItr;
      }
      ++originItr;
    }
  }

  void VisibleObjectManager::draw(char stateSignal) {
    auto itr = this->objects.begin();
    while (itr != this->objects.end()) {
      if (itr->first[0] == stateSignal) {
        itr->second->draw();
      }
      ++itr;
    }
  }
}