#ifndef GAME_VISIBLE_OBJECT_MANAGER_H
#define GAME_VISIBLE_OBJECT_MANAGER_H

#include "visible-object.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace pong {
  class VisibleObjectManager {
    public:
      VisibleObjectManager() = default;
      ~VisibleObjectManager() = default;
      void init();
      void handleInput();
      void update(float elapsedTime);
      void draw();
      void addObject(VisibleObject *object);
      void removeObject(VisibleObject *object);
      void clearObjects();
      VisibleObject *getObject(int index);
      int getObjectCount();
    private:
      std::vector<VisibleObject *> objects;
  };
}

#endif /// GAME_VISIBLE_OBJECT_MANAGER_H