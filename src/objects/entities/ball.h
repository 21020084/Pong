#ifndef OBJ_BALL_H
#define OBJ_BALL_H

#include <cmath>
#include "../visible-object.h"
#include "player.h"

namespace pong {
  class Ball : public VisibleObject {
    public:
      Ball(sf::FloatRect constraints, GameDataRef _data);
      void resetPosition(sf::Vector2f player1Position, sf::Vector2f player2Position);
      void handleInput(sf::Event &event) override;
      void update(float elapsedTime) override;
      void reset();
      float getSpeed();
      void setSpeed(float speed);
      void collideWith(VisibleObject *target) override;
      bool isOut;
      float timeElapsed;
      enum CollidedWith {
        LEFT,
        RIGHT
      } collidedWith;

    private:
      int angle;
      float speed;
      float maxSpeed;
      sf::FloatRect constraints;
  };
}

#endif // OBJ_BALL_H