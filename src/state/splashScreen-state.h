#ifndef SPLASHSCREEN_STATE_H
#define SPLASHSCREEN_STATE_H

#define SPLASH_STATE_SHOW_TIME 3.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "assets/splashscreen.png"

#include "Game-state.h"
#include "../Game.h"

namespace pong {
  class SplashscreenState : public GameState {
    public:
      SplashscreenState(GameDataRef _data);

      int init() override;
      void handleInput() override;
      void update(float timeElapsed) override;
      void render() override;
      bool hasExited() override;
    private:
      GameDataRef data;
      sf::Sprite sprite;
      sf::Clock clock;
  };
}

#endif /// SPLASHSCREEN_STATE_H