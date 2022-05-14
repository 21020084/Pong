#ifndef OBJ_PLAYER_H
#define OBJ_PLAYER_H

#include "../visible-object.h"
#include "ball.h"

namespace pong {

  class Player : public VisibleObject {
    public:
      // Player(GameDataRef _data);
      Player(float Top, float Bottom);
      void handleInput(sf::Event &event) override;
      void update(float elapsedTime) override;
      void runAI();
      void setAI(bool ai);
      bool isAI();
      float getSpeed();
      void setSpeed(float speed);

    private:
      // GameDataRef data;
      bool ai;

      enum Direction {
        UP,
        DOWN,
        NONE
      };

      Direction direction = NONE;
      float speed = 800.0f;
      float acceleration = 200.0f;
      float deceleration = 200.0f;
      float constrainTop = 0.0f;
      float constrainBottom = 0.0f;
  };
}

#endif // OBJ_PLAYER_H