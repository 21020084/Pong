#include <stdexcept>

#include "ball.h"
#include "../../DEFINITION.h"
#define M_PI 3.141592653589

namespace pong {
  Ball::Ball(sf::FloatRect constraints, GameDataRef _data) : VisibleObject("assets/ball.png", _data) {
    this->speed = 10.0f;
    this->maxSpeed = 50.0f;
    this->angle = 140;
    this->constraints = constraints;
    this->isOut = false;
    this->timeElapsed = 0.0f;
    this->collidedWith = RIGHT;
  }

  void Ball::resetPosition(sf::Vector2f player1Position, sf::Vector2f player2Position) {
    if (this->collidedWith == LEFT) {
      this->setPosition(player1Position.x + 15.0f, player1Position.y + 65.0f);
    } else {
      this->setPosition(player2Position.x - 34.0f, player1Position.y + 65.0f);
    }

    // this->setPosition(this->constraints.width / 2, this->constraints.height / 2);
    // this->speed = 300.0f;
    // this->isOut = false;
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
    if (this->isOut) return;

    this->timeElapsed += _elapsedTime;
    if (this->timeElapsed < 2.0f) return;

    float velocity = this->speed * timeElapsed;
    float angleInRadian = angle * M_PI / 180.0f;
    float velocityX = velocity * std::cos(angleInRadian) - 0 * std::sin(angleInRadian);
    float velocityY = 0 * std::cos(angleInRadian) + velocity * std::sin(angleInRadian);

    // Handle bounce with the top & bottom walls
    if (this->getTop() + velocityY <= this->constraints.top + 10
    || this->getBottom() + velocityY >= this->constraints.top + this->constraints.height - 10) {
      this->angle = 360 - this->angle;
      velocityY *= -1;
    }

    // Handle loss condition
    if (this->getLeft() + velocityX <= this->constraints.left + 10) {
      // throw std::runtime_error("Player 2 wins!");
      this->setPosition(this->constraints.left + 10, this->getPosition().y);
      this->isOut = true;
      this->collidedWith = RIGHT;
    } else if (this->getRight() + velocityX >= this->constraints.left + this->constraints.width - 10) {
      // throw std::runtime_error("Player 1 wins!");
      this->setPosition(this->constraints.left + this->constraints.width - 10, this->getPosition().y);
      this->isOut = true;
      this->collidedWith = LEFT;
    }

    move(velocityX, velocityY);
  }

  void Ball::collideWith(VisibleObject *target) {
    if (isOut) return;
    if (!dynamic_cast<Player*>(target)) return;
      // throw std::logic_error("Ball::collideWith() - target is not a Player");

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