#ifndef ONE_PLAYER_BUTTON
#define ONE_PLAYER_BUTTON

#include "../visible-object.h"

namespace pong { 

  class OnePlayerButton : public VisibleObject {
    public:
      OnePlayerButton(GameDataRef _data);
      void handleInput(sf::Event &event) override;
      void update(float elapsedTime) override {}
  };
}


#endif // ONE_PLAYER_BUTTON