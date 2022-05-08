#ifndef SPLASHSCREEN_STATE_H
#define SPLASHSCREEN_STATE_H

#define SPLASH_STATE_SHOW_TIME 1.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "assets/splashscreen.png"

#include "Game-state.h"
// #include "../Game.h"

namespace pong {

  struct GameData;
  typedef std::shared_ptr<GameData> GameDataRef;

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
      sf::Clock clock;
  };
}

#endif /// SPLASHSCREEN_STATE_H