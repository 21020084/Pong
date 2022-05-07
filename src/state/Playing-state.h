#ifndef PLAYING_STATE_H
#define PLAYING_STATE_H

#include "Game-state.h"

namespace pong  {
  class PlayingState : public GameState {
    public:
      int init() override;
      void handleInput() override;
      void update(float timeElapsed) override;
      void render() override;
  };
}

#endif /// PLAYING_STATE_H