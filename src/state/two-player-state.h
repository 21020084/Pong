#ifndef TWO_PLAYER_STATE_H
#define TWO_PLAYER_STATE_H

#include "game-state.h"

namespace pong {
    class TwoPlayerState : public GameState {
      public:
        TwoPlayerState (GameDataRef _data);

        int init() override;
        void handleInput() override;
        void update(float timeElapsed) override;
        void render() override;
    };
  
}

#endif // TWO_PLAYER_STATE_H