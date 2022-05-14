#ifndef OBJ_BALL_H
#define OBJ_BALL_H

#include <cmath>
#include "../visible-object.h"
#include "player.h"
#define M_PI 3.141592653589

namespace pong {
  class Ball : public VisibleObject {
    public:
      Ball(sf::FloatRect constraints);
      bool isOut;
      void handleInput(sf::Event &event) override;
      void update(float elapsedTime) override {}
      void reset();
      float getSpeed();
      void setSpeed(float speed);
      void collideWith(VisibleObject *target) override;

    private:
      int angle;
      float speed;
      float maxSpeed;
      float timeElapsed;
      enum CollidedWith : bool{
        LEFT,
        RIGHT
      } collidedWith;
      sf::FloatRect constraints;
  };
}

#endif // OBJ_BALL_H