#ifndef TWO_PLAYER_STATE_H
#define TWO_PLAYER_STATE_H

#include "game-state.h"
#include "../DEFINITION.h"

namespace pong {
    class TwoPlayerState : public GameState {
      public:
        TwoPlayerState (GameDataRef _data);
        ~TwoPlayerState();

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

#endif // TWO_PLAYER_STATE_H