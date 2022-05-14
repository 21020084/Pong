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
    GameOver,
    Exiting
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
      bool hasEntered();
      bool hasClosed();
      void setNewState();
      void enter();
      // virtual void endLoopLogic() {};

    protected:
      GameDataRef data;
      bool m_hasEntered;
      bool m_hasClosed;
  };
}

#endif /// GAME_GAMESTATE_H