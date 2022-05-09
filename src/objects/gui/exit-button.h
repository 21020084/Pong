#ifndef EXIT_BUTTON_H
#define EXIT_BUTTON_H

#include "../visible-object.h"

namespace pong {
  struct GameData;
  typedef std::shared_ptr<GameData> GameDataRef;

  class ExitButton : public VisibleObject {
    public:
      ExitButton(GameDataRef _data);
      void loadTexture(std::string textureFilename) override;
      void handleInput() override;
      void update(float elapsedTime) override;
  };
}

#endif // EXIT_BUTTON_H