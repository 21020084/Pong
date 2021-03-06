#ifndef EXIT_BUTTON_H
#define EXIT_BUTTON_H

#include "../visible-object.h"

namespace pong { 

  class ExitButton : public VisibleObject {
    public:
      ExitButton(GameDataRef _data);
      void handleInput(sf::Event &event) override;
      void update(float elapsedTime) override {}
  };
}

#endif // EXIT_BUTTON_H