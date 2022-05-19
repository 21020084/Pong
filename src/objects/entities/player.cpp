#include "player.h"
#include "ball.h"
#include "../../Game.h"
#include "../../DEFINITION.h"

namespace pong {
  Player::Player(float Top, float Bottom,  bool isLeft, GameDataRef _data) : VisibleObject("assets/player.png", _data) {
    this->constrainTop = Top;
    this->constrainBottom = Bottom;
    this->left = isLeft;
    this->ai = false;
    this->freezeTimer = 1.0f;
  }

  void Player::handleInput(sf::Event &event) {
    if (this->ai) {
      return;
    }

    if (!this->left) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        this->direction = UP;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        this->direction = DOWN;
      } else {
        this->direction = NONE;
      }
    } else {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        this->direction = UP;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        this->direction = DOWN;
      } else {
        this->direction = NONE;
      }
    }
    
  }

  void Player::update(float elapsedTime) {
    this->freezeTimer -= elapsedTime;
    if (this->freezeTimer > 0.0f) {
      return;
    }

    if (this->ai) {
      this->runAI();
    }
    if (this->direction == UP) {
      this->move(0, -this->speed);
    } else if (this->direction == DOWN) {
      this->move(0, this->speed);
    }
    
    /// Constrain the player to the screen
    sf::Vector2f curPosition = this->getPosition();
    if (curPosition.y < this->constrainTop + 20) {
      this->setPosition(curPosition.x, this->constrainTop + 20);
      /// height of the player is 150 pixels
    } else if (curPosition.y > this->constrainBottom - 150) {
      this->setPosition(curPosition.x, this->constrainBottom - 150);
    }
  }

  void Player::runAI() {
    if (!this->ai) {
      return;
    }

    Ball *ball = dynamic_cast<Ball*>(this->data->visibleObjectManager.getObject("O_ball"));
    if (ball == nullptr) {
      return;
    }
    
    /// The AI start moving
    if (ball->getPosition().x - this->getPosition().x >= SCREEN_WIDTH / 2 - 50) return;

    float ballY = ball->getPosition().y;
    float playerY = this->getPosition().y;
    float ballHeight = ball->getBoundingBox().height;
    float playerHeight = this->getBoundingBox().height;
    float ballCenterY = ballY + ballHeight / 2;
    float playerCenterY = playerY + playerHeight / 2;

    if (playerY < ballCenterY && ballCenterY < playerY + playerHeight) {
      this->direction = NONE;
      return;
    }

    if (ballCenterY < playerCenterY) {
      this->direction = UP;
    } else if (ballCenterY > playerCenterY) {
      this->direction = DOWN;
    } else {
      this->direction = NONE;
    }
  }

  void Player::resetFreezeTimer() {
    this->freezeTimer = FREEZING_TIME;
  }

  void Player::setAI(bool _ai) {
    this->ai = _ai;
  }

  bool Player::isAI() {
    return this->ai;
  }

  float Player::getSpeed() {
    return this->speed;
  }

  void Player::addSpeed(float _speed) {
    this->speed += _speed;
  }
}