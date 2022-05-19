#include <stdexcept>

#include "ball.h"
#include "../../DEFINITION.h"
#define M_PI 3.141592653589

namespace pong {
  Ball::Ball(sf::FloatRect constraints, GameDataRef _data) : VisibleObject("assets/ball.png", _data) {
    this->speed = BALL_BASE_SPEED;
    this->maxSpeed = BALL_MAX_SPEED;
    this->angle = 1.0f * (rand() % 161) + 100;
    // this->angle = -90.0f;
    this->constraints = constraints;
    this->is_out = false;
    this->freezeTimer = FREEZING_TIME;
    this->collidedWith = RIGHT;

    this->ballOutSoundBuffer.loadFromFile("assets/ball_out.wav");
    this->ballOutSound.setBuffer(this->ballOutSoundBuffer);
    this->ballOutSound.setVolume(30);
    /// Load ball hit sound
    this->ballHitSoundBuffer.resize(2);
    this->ballHitSoundBuffer[0].loadFromFile("assets/ball_hit(0).wav");
    this->ballHitSoundBuffer[1].loadFromFile("assets/ball_hit(1).wav");
    // this->ballHitSound.setBuffer(this->ballHitSoundBuffer[0]);

    this->winningSoundBuffer.loadFromFile("assets/winning.wav");
    this->winningSound.setBuffer(this->winningSoundBuffer);
    this->losingSoundBuffer.loadFromFile("assets/losing.wav");
    this->losingSound.setBuffer(this->losingSoundBuffer);
  }

  void Ball::resetPosition(VisibleObject *player1, VisibleObject *player2) {
    if (this->getLeft() > SCREEN_WIDTH / 2) {
      this->setPosition(player1->getPosition().x + 15.0f, player1->getPosition().y + 65.0f);
    } else {
      this->setPosition(player2->getPosition().x - 34.0f, player2->getPosition().y + 65.0f);
    }   
  }

  void Ball::resetFreezeTimer() {
    this->freezeTimer = FREEZING_TIME;
  }

  void Ball::handleInput(sf::Event &event) {}

  void Ball::update(float _elapsedTime) {
    if (this->is_out) return;

    this->freezeTimer -= _elapsedTime;
    if (this->freezeTimer > 0.0f) return;

    float velocity = this->speed * 1.0f;
    float angleInRadian = this->angle * M_PI / 180.0f;
    float velocityX = velocity * std::cos(angleInRadian) - 0 * std::sin(angleInRadian);
    float velocityY = 0 * std::cos(angleInRadian) + velocity * std::sin(angleInRadian);

    /************** Handle bounce with the top & bottom walls **************/
    if (this->getTop() - 5 <= this->constraints.top
    || this->getBottom() + 5 >= this->constraints.top + this->constraints.height) {
      /// Play sound
      this->ballHitSound.setBuffer(this->ballHitSoundBuffer[0]);
      this->ballHitSound.play();
      /////
      this->angle = 360 - this->angle;
      velocityY *= -1;
    }
    /***********************************************************************/


    /************************* Handle ball out condition **********************/
    if (this->getLeft() <= this->constraints.left) {
      // throw std::runtime_error("Player 2 wins!");
      this->ballOutSound.play();
      this->setPosition(this->constraints.left, this->getPosition().y);
      this->is_out = true;
      // this->collidedWith = RIGHT;
    } else if (this->getRight() >= this->constraints.left + this->constraints.width) {
      // throw std::runtime_error("Player 1 wins!");
      this->ballOutSound.play();
      this->setPosition(this->constraints.left + this->constraints.width, this->getPosition().y);
      this->is_out = true;
      // this->collidedWith = LEFT;
      /************************************************************************/
    }

    move(velocityX, velocityY);
  }
  int debug = 0;
  void Ball::collideWith(VisibleObject *target) {
    if (this->is_out) return;
    if (!dynamic_cast<Player*>(target)) return;
      // throw std::logic_error("Ball::collideWith() - target is not a Player");
    this->ballHitSound.setBuffer(this->ballHitSoundBuffer[1]);
    this->ballHitSound.play();

    /// In the begining of a turn
    if (this->collidedWith == LEFT && target->getLeft() < SCREEN_WIDTH / 2) return;
    if (this->collidedWith == RIGHT && target->getRight() > SCREEN_WIDTH / 2) return;

    float paddleCenterY = (target->getTop() + target->getBottom()) / 2;
    float ballCenterY = (this->getTop() + this->getBottom()) / 2;
    float distDiff = ballCenterY - paddleCenterY;
    float maxDiff = target->getBoundingBox().height;

    float normalizedDiff = distDiff / maxDiff;

    if (target->getPosition().x < SCREEN_WIDTH / 2) {
        this->angle = normalizedDiff * 90; // Between -45 and 45 degree
    } else {
        this->angle = 180 - normalizedDiff * 90;
    }
    this->collidedWith = (this->collidedWith == LEFT) ? RIGHT : LEFT;
  }

  float Ball::getSpeed() {
    return this->speed;
  }

  bool Ball::addSpeed(float speed) {
    if (this->speed + speed > this->maxSpeed) {
      return false;
    }
    this->speed += speed;
    return true;
  }

  float Ball::getAngle() {
    return this->angle;
  }

  void Ball::setAngle(float _angle) {
    this->angle = _angle;
  }
}