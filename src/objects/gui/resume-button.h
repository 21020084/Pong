#ifndef RESUME_BUTTON_H
#define RESUME_BUTTON_H

#include "../visible-object.h"

namespace pong { 

  class ResumeButton : public VisibleObject {
    public:
      ResumeButton(GameDataRef _data);
      void handleInput(sf::Event &event) override;
      void update(float elapsedTime) override {}
  };
}

#endif // RESUME_BUTTON_H