#ifndef OBJ_BALL_H
#define OBJ_BALL_H

#include <cmath>
#include "../visible-object.h"
#include "player.h"

namespace pong {
  class Ball : public VisibleObject {
    public:
      Ball(sf::FloatRect constraints, GameDataRef _data);
      void resetPosition(VisibleObject *player1, VisibleObject *player2);
      void handleInput(sf::Event &event) override;
      void update(float elapsedTime) override;
      void reset();
      float getSpeed();
      void setSpeed(float _speed);
      float getAngle();
      void setAngle(float _angle);
      void collideWith(VisibleObject *target) override;
      bool isOut() {return is_out;}
      void setOut(bool val) {is_out = val;}
      float timeElapsed;
      enum CollidedWith {
        LEFT,
        RIGHT
      } collidedWith;

    private:
      bool is_out;
      int angle;
      float speed;
      float maxSpeed;
      sf::FloatRect constraints;
  };
}

#endif // OBJ_BALL_H