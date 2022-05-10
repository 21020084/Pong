#ifndef OBJ_FIELD_H
#define OBJ_FIELD_H

#include "../visible-object.h"

namespace pong {

  class Field : public VisibleObject {
    public:
      Field(std::string textureFilename, GameDataRef _data);
      void handleInput(sf::Event &event) override;
      void update(float elapsedTime) override {}
      void draw() override;

  };
}

#endif // OBJ_FIELD_H