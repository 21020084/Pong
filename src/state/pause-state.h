#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include "Game-state.h"

namespace pong {

  class PauseState : public GameState {
    public:
      PauseState(GameDataRef _data);

      int init() override;
      void handleInput() override;
      void update(float timeElapsed) override;
      void render() override;
    private:
      sf::Texture m_backgroundTexture;
      sf::Sprite m_backgroundSprite;
      sf::Texture resumeTexture;
      sf::Sprite resumeSprite;
      sf::Texture mainMenuTexture;
      sf::Sprite mainMenuSprite;
  };
}

#endif /// PAUSE_STATE_H