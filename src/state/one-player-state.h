#ifndef ONE_PLAYER_STATE_H
#define ONE_PLAYER_STATE_H

#include "game-state.h"
#include "../DEFINITION.h"

namespace pong {
    class OnePlayerState : public GameState {
      public:
        OnePlayerState (GameDataRef _data);
        ~OnePlayerState();

        int init() override;
        void handleInput() override;
        void update(float timeElapsed) override;
        void render() override;
        void handleTurnChanging();

      private:
        int score1, score2, winningScore;
        sf::Text scoreText1, scoreText2;
        sf::Font scoreFont;
        float ballSpeed = BALL_BASE_SPEED;
      };
}

#endif // ONE_PLAYER_STATE_H