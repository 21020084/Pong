#ifndef SPLASHSCREEN_STATE_H
#define SPLASHSCREEN_STATE_H

#define SPLASH_STATE_SHOW_TIME 1.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "assets/splashscreen.png"

#include "Game-state.h"

namespace pong {

  class SplashScreenState : public GameState {
    public:
      SplashScreenState(GameDataRef _data);

      int init() override;
      void handleInput() override;
      void update(float timeElapsed) override;
      void render() override;

    private:
      sf::Texture texture;
      sf::Sprite sprite;
  };
}

#endif /// SPLASHSCREEN_STATE_H