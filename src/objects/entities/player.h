#ifndef OBJ_PLAYER_H
#define OBJ_PLAYER_H

#include "../visible-object.h"

namespace pong {
  struct GameData;
  typedef std::shared_ptr<GameData> GameDataRef;

  class Player : public VisibleObject {
    public:
      Player(GameDataRef _data);
      void handleInput(sf::Event &event) override;
  };
}

#endif // OBJ_PLAYER_H