#include "player.h"
#include "ball.h"
#include "../../Game.h"

namespace pong {
  Player::Player(float Top, float Bottom, GameDataRef _data) : VisibleObject("assets/player.png", _data) {
    this->constrainTop = Top;
    this->constrainBottom = Bottom;
    this->ai = false;
  }

  void Player::handleInput(sf::Event &event) {
    if (this->ai) {
      return;
    }

    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Up) {
        this->direction = UP;
      } else if (event.key.code == sf::Keyboard::Down) {
        this->direction = DOWN;
      }
    } else if (event.type == sf::Event::KeyReleased) {
      this->direction = NONE;
    }
  }

  void Player::update(float elapsedTime) {
    if (this->ai) {
      this->runAI();
      return;
    }

    /// Move the player up or down
    if (this->direction == UP) {  
      this->move(0, -this->speed * elapsedTime);
    } else if (this->direction == DOWN) {
      this->move(0, this->speed * elapsedTime);
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

    Ball *ball = dynamic_cast<Ball*>(this->data->visibleObjectManager.getObject("ball"));
    if (ball->getPosition().y < this->getPosition().y) {
      this->direction = UP;
    } else if (ball->getPosition().y > this->getPosition().y) {
      this->direction = DOWN;
    } else {
      this->direction = NONE;
    }
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

  void Player::setSpeed(float _speed) {
    this->speed = _speed;
  }
}