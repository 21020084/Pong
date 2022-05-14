#ifndef ONE_PLAYER_STATE_H
#define ONE_PLAYER_STATE_H

#include "game-state.h"

namespace pong {
    class OnePlayerState : public GameState {
      public:
        OnePlayerState (GameDataRef _data);

        int init() override;
        void handleInput() override;
        void update(float timeElapsed) override;
        void render() override;
    };
  
}

#endif // ONE_PLAYER_STATE_H