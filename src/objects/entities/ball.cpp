#include <stdexcept>

#include "ball.h"
#include "../../DEFINITION.h"
#define M_PI 3.141592653589

namespace pong {
  Ball::Ball(sf::FloatRect constraints, GameDataRef _data) : VisibleObject("assets/ball.png", _data) {
    this->speed = 500.0f;
    this->maxSpeed = 1000.0f;
    this->angle = 0;
    this->constraints = constraints;
    this->isOut = false;
    this->timeElapsed = 0.0f;
  }

  void Ball::handleInput(sf::Event &event) {
    // if (event.type == sf::Event::KeyPressed) {
    //   if (event.key.code == sf::Keyboard::Space) {
    //     this->reset();
    //   }
    // }
  }

  void Ball::update(float _elapsedTime) {
    if (this->isOut) return;

    this->timeElapsed += _elapsedTime;
    if (this->timeElapsed < 1.0f) return;

    float velocity = this->speed * timeElapsed;
    float angleInRadian = angle * M_PI / 180.0f;
    float velocityX = velocity * std::cos(angleInRadian) - 0 * std::sin(angleInRadian);
    float velocityY = 0 * std::cos(angleInRadian) + velocity * std::sin(angleInRadian);

    // Handle bounce with the top & bottom walls
    if (this->getTop() + velocityY <= this->constraints.top 
    || getBottom() + velocityY >= this->constraints.top + this->constraints.height) {
      this->angle = 360 - this->angle;
      velocityY *= -1;
    }

    // Handle loss condition
    if (this->getLeft() + velocityX <= this->constraints.left 
    || getRight() + velocityX >= this->constraints.left + this->constraints.width) {
      isOut = true;
    }

    move(velocityX, velocityY);
  }

  void Ball::collideWith(VisibleObject *target) {
    if (isOut) return;
    if (!dynamic_cast<Player*>(target)) 
      throw std::logic_error("Ball::collideWith() - target is not a Player");

    this->collidedWith = (this->collidedWith == LEFT) ? RIGHT : LEFT;

    float paddleCenterY = (target->getTop() + target->getBottom()) / 2;
    float ballCenterY = (this->getTop() + this->getBottom()) / 2;
    float distDiff = ballCenterY - paddleCenterY;
    float maxDiff = target->getBoundingBox().height;

    float normalizedDiff = distDiff / maxDiff;

    if (target->getPosition().x < SCREEN_WIDTH / 2) {
        this->angle = (int)(normalizedDiff * 90); // Between -45 and 45 degree
    } else {
        this->angle = 180 - (int)(normalizedDiff * 90);
    }
  }
}