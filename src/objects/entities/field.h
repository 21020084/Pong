#ifndef OBJ_FIELD_H
#define OBJ_FIELD_H

#include "../visible-object.h"

namespace pong {
  struct GameData;
  typedef std::shared_ptr<GameData> GameDataRef;

  class Field : public VisibleObject {
    public:
      Field(GameDataRef _data);
      void loadTexture(std::string textureFilename) override;
      void update(float elapsedTime) override;
  };
}

#endif // OBJ_FIELD_H