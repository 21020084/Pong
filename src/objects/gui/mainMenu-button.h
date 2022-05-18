#ifndef MAIN_MENU_BUTTON
#define MAIN_MENU_BUTTON

#include "../visible-object.h"

namespace pong { 

  class MainMenuButton : public VisibleObject {
    public:
      MainMenuButton(GameDataRef _data);
      void handleInput(sf::Event &event) override;
      void update(float elapsedTime) override {}
  };
}


#endif // MAIN_MENU_BUTTON