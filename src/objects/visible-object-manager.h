#ifndef GAME_VISIBLE_OBJECT_MANAGER_H
#define GAME_VISIBLE_OBJECT_MANAGER_H

#include "visible-object.h"
#include <SFML/Graphics.hpp>

namespace pong {
  class VisibleObjectManager {
    public:
      VisibleObjectManager();
      ~VisibleObjectManager();
      void init();
      void handleInput(sf::Event &event);
      void update(float elapsedTime);
      void draw(sf::RenderWindow &window);
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