#ifndef ONE_PLAYER_STATE_H
#define ONE_PLAYER_STATE_H

#include "game-state.h"

namespace pong {
    class OnePlayerState : public GameState {
      public:
        OnePlayerState (GameDataRef _data);

        int init() override;
        void reset();
        void handleInput() override;
        void update(float timeElapsed) override;
        void render() override;
        void endLoopLogic() override;

      private:
        int score1, score2, winningScore;
        sf::Text scoreText1, scoreText2;
        sf::Font scoreFont;

        bool gameOver = 0;
        sf::Text gameOverText; 
    };
}

#endif // ONE_PLAYER_STATE_H