#include <stdexcept>

#include "ball.h"
#include "../../DEFINITION.h"
#define M_PI 3.141592653589

namespace pong {
  Ball::Ball(sf::FloatRect constraints, GameDataRef _data) : VisibleObject("assets/ball.png", _data) {
    this->speed = 15.0f;
    this->maxSpeed = 50.0f;
    this->angle = -120.0f;
    this->constraints = constraints;
    this->is_out = false;
    this->timeElapsed = 0.01f;
    this->collidedWith = RIGHT;
  }

  void Ball::resetPosition(VisibleObject *player1, VisibleObject *player2) {
    if (this->collidedWith == LEFT) {
      this->setPosition(player1->getPosition().x + 15.0f, player1->getPosition().y + 65.0f);
    } else {
      this->setPosition(player2->getPosition().x - 34.0f, player2->getPosition().y + 65.0f);
    }

    // this->setPosition(this->constraints.width / 2, this->constraints.height / 2);
    // this->speed = 300.0f;
    // this->is_out = false;
    // this->timeElapsed = 0.0f;
    // this->collidedWith = RIGHT;    
  }

  void Ball::handleInput(sf::Event &event) {
    // if (event.type == sf::Event::KeyPressed) {
    //   if (event.key.code == sf::Keyboard::Space) {
    //     this->reset();
    //   }
    // }
  }

  void Ball::update(float _elapsedTime) {
    if (this->is_out) return;

    // sf::Clock clock;
    // this->timeElapsed += clock.getElapsedTime().asSeconds();
    this->timeElapsed += _elapsedTime;

    if (this->timeElapsed < 2.0f) return;

    float velocity = this->speed * 1.0f;
    float angleInRadian = this->angle * M_PI / 180.0f;
    float velocityX = velocity * std::cos(angleInRadian) - 0 * std::sin(angleInRadian);
    float velocityY = 0 * std::cos(angleInRadian) + velocity * std::sin(angleInRadian);

    // Handle bounce with the top & bottom walls
    if (this->getTop() + velocityY <= this->constraints.top
    || this->getBottom() + velocityY >= this->constraints.top + this->constraints.height) {
      this->angle = 360 - this->angle;
      velocityY *= -1;
    }

    // Handle loss condition
    if (this->getLeft() <= this->constraints.left) {
      // throw std::runtime_error("Player 2 wins!");
      this->setPosition(this->constraints.left, this->getPosition().y);
      this->is_out = true;
      // this->collidedWith = RIGHT;
    } else if (this->getRight() >= this->constraints.left + this->constraints.width) {
      // throw std::runtime_error("Player 1 wins!");
      this->setPosition(this->constraints.left + this->constraints.width, this->getPosition().y);
      this->is_out = true;
      // this->collidedWith = LEFT;
    }

    move(velocityX, velocityY);
  }
  int debug = 0;
  void Ball::collideWith(VisibleObject *target) {
    if (this->is_out) return;
    if (!dynamic_cast<Player*>(target)) return;
      // throw std::logic_error("Ball::collideWith() - target is not a Player");

    /// Start a new turn
    if (this->collidedWith == LEFT && target->getLeft() < SCREEN_WIDTH / 2) return;
    if (this->collidedWith == RIGHT && target->getRight() > SCREEN_WIDTH / 2) return;

    ++debug;

    if (debug == 2) {
      debug += 0;
    }

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

  void Ball::setSpeed(float speed) {
    this->speed = speed;
  }

  float Ball::getAngle() {
    return this->angle;
  }

  void Ball::setAngle(float _angle) {
    this->angle = _angle;
  }
}