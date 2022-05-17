#ifndef TWO_PLAYER_STATE_H
#define TWO_PLAYER_STATE_H

#include "game-state.h"

namespace pong {
    class TwoPlayerState : public GameState {
      public:
        TwoPlayerState (GameDataRef _data);

        int init() override;
        void handleInput() override;
        void update(float timeElapsed) override;
        void render() override;

      private:
        int score1, score2, winningScore;
        sf::Text scoreText1, scoreText2;
        sf::Font scoreFont;

        bool gameOver = 0;
        sf::Text gameOverText;
    };
  
}

#endif // TWO_PLAYER_STATE_H