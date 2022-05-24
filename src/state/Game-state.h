#ifndef GAME_GAMESTATE_H
#define GAME_GAMESTATE_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../objects/visible-object-manager.h"

namespace pong {
  enum StateID {
    SplashScreen,
    Menu,
    OnePlayer,
    TwoPlayer,
    Pause,
    None
  };

  struct GameData;
  typedef std::shared_ptr<GameData> GameDataRef;

  class GameState {
    public:
      GameState(GameDataRef _data);
      virtual ~GameState() = default;
      virtual int init() = 0;
      virtual void handleInput() = 0;
      virtual void update(float elapsedTime) = 0;
      virtual void render() = 0;

      StateID getID();
      bool added();
      bool removed();
      void setNewState();
      void add();
      void entering();
      void remove();
      void exiting();

    protected:
      GameDataRef data;
      bool m_added;
      bool m_entered;
      bool m_removed;
      StateID m_ID;
      sf::Clock clock;
      sf::Texture transitionTexture;
      sf::Sprite transitionSprite;
  };
}

#endif /// GAME_GAMESTATE_H