#ifndef TWO_PLAYER_BUTTON
#define TWO_PLAYER_BUTTON

#include "../visible-object.h"

namespace pong { 

  class TwoPlayerButton : public VisibleObject {
    public:
      TwoPlayerButton(GameDataRef _data);
      void handleInput(sf::Event &event) override;
      void update(float elapsedTime) override {}
  };
}


#endif // TWO_PLAYER_BUTTON