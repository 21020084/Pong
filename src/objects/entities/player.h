#ifndef OBJ_PLAYER_H
#define OBJ_PLAYER_H

#include "../visible-object.h"

namespace pong {

  class Player : public VisibleObject {
    public:
      Player(float Top, float Bottom, bool isLeft, GameDataRef _data);
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
      bool left;

      enum Direction {
        UP,
        DOWN,
        NONE
      };

      Direction direction = NONE;
      float speed = 950.0f;
      float constrainTop = 0.0f;
      float constrainBottom = 0.0f;
  };
}

#endif // OBJ_PLAYER_H