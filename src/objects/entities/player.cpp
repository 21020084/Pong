#include "player.h"
// #include "ball.h"

namespace pong {
  Player::Player(float Top, float Bottom) : VisibleObject("assets/player.png") {
    this->constrainTop = Top;
    this->constrainBottom = Bottom;
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
    }

    /// Move the player up or down
    if (this->direction == UP) {  
      this->move(0, -this->speed * elapsedTime);
    } else if (this->direction == DOWN) {
      this->move(0, this->speed * elapsedTime);
    }

    /// Constrain the player to the screen
    sf::Vector2f curPosition = this->getPosition();
    if (curPosition.y < this->constrainTop) {
      this->setPosition(curPosition.x, this->constrainTop);
    } else if (curPosition.y > this->constrainBottom) {
      this->setPosition(curPosition.x, this->constrainBottom);
    }

    // this->direction = NONE;
  }

  void Player::runAI() {
    

    // this->direction = NONE;
  }
}