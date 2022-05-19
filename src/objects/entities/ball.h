#ifndef OBJ_BALL_H
#define OBJ_BALL_H

#include <SFML/Audio.hpp>
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
      bool addSpeed(float _speed);
      float getAngle();
      void setAngle(float _angle);
      void resetFreezeTimer();
      void collideWith(VisibleObject *target) override;
      bool isOut() {return is_out;}
      void setOut(bool val) {is_out = val;}
      enum CollidedWith {
        LEFT,
        RIGHT
      } collidedWith;

    private:
      bool is_out;
      float angle;
      float speed;
      float maxSpeed;
      float freezeTimer;
      sf::FloatRect constraints;
      sf::Sound ballOutSound;
      sf::SoundBuffer ballOutSoundBuffer;
      sf::Sound ballHitSound;
      std::vector<sf::SoundBuffer> ballHitSoundBuffer;
      sf::Sound winningSound;
      sf::SoundBuffer winningSoundBuffer;
      sf::Sound losingSound;
      sf::SoundBuffer losingSoundBuffer;
  };
}

#endif // OBJ_BALL_H