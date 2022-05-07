#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "Game-state.h"
#include "../Game.h"

namespace pong {
  class MenuState : public GameState {
    public:
      MenuState(GameDataRef _data);

      int init() override;
      void handleInput() override;
      void update(float timeElapsed) override;
      void render() override;
    private:
      GameDataRef data;
      sf::Texture m_backgroundTexture;
      sf::Sprite m_backgroundSprite;
      sf::Texture onePlayerTexture;
      sf::Sprite onePlayerSprite;
      sf::Texture twoPlayerTexture;
      sf::Sprite twoPlayerSprite;
      sf::Texture exitTexture;
      sf::Sprite exitSprite;
  };
}

#endif /// MENU_STATE_H