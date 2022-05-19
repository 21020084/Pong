#ifndef GAME_VISIBLE_OBJECT_MANAGER_H
#define GAME_VISIBLE_OBJECT_MANAGER_H

#include "visible-object.h"
#include <map>

namespace pong {
  class VisibleObjectManager {
    public:
      VisibleObjectManager() = default;
      ~VisibleObjectManager();
      void handleInput(sf::Event &event, char stateSignal);
      void update(float elapsedTime, char stateSignal);
      void draw(char stateSignal);
      void addObject(std::string name, VisibleObject *object);
      void removeObject(std::string name);
      void clearObjects();
      VisibleObject *getObject(std::string name);
    private:
      std::map<std::string, VisibleObject *> objects;
  };
}

#endif /// GAME_VISIBLE_OBJECT_MANAGER_H