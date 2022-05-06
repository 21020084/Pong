#ifndef PLAYING_STATE_H
#define PLAYING_STATE_H

#include "Game-state.h"

namespace pong  {
  class PlayingState : public GameState {
    public:
      void init() override;
      void handleInput(sf::Event &event) override;
      void update(float timeElapsed) override;
      void draw(sf::RenderWindow &window) override;
  };
}

#endif /// PLAYING_STATE_H