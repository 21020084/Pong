#ifndef GAME_VISIBLE_OBJECT_MANAGER_H
#define GAME_VISIBLE_OBJECT_MANAGER_H

#include "visible-object.h"
#include <map>

namespace pong {
  class VisibleObjectManager {
    public:
      VisibleObjectManager() = default;
      ~VisibleObjectManager() = default;
      void handleInput(sf::Event &event);
      void update(float elapsedTime);
      void draw();
      void addObject(std::string name, VisibleObject *object);
      void removeObject(std::string name);
      void clearObjects();
      VisibleObject *getObject(std::string name);
      int getObjectCount();
    private:
      std::map<std::string, VisibleObject *> objects;
  };
}

#endif /// GAME_VISIBLE_OBJECT_MANAGER_H