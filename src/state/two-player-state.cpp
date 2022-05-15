#include <stdexcept>

#include "two-player-state.h"
#include "../objects/visible-object.h"
#include "../objects/entities/field.h"
#include "../objects/entities/ball.h"
#include "../objects/entities/player.h"
#include "../Game.h"
#include "../DEFINITION.h"

namespace pong {
  TwoPlayerState::TwoPlayerState(GameDataRef _data) : GameState(_data) {}

  int TwoPlayerState::init() {
    this->data->cursor.loadFromSystem(sf::Cursor::Arrow);
    this->data->window.setMouseCursor(this->data->cursor);
    this->data->visibleObjectManager.clearObjects();

    ////////////////////Initialize the game objects/////////////////////////////
    Field *field = new Field(Game::data);
    field->setPosition(0, 0);
    this->data->visibleObjectManager.addObject("Field", field);

    float leftEdge = field->getLeft();
    float rightEdge = field->getRight();
    float topEdge = field->getTop();
    float bottomEdge = field->getBottom();

    float width = rightEdge - leftEdge;
    float height = bottomEdge - topEdge;

    sf::FloatRect ballConstraint = sf::FloatRect(leftEdge + 10, topEdge + 10, width - 20, height - 20);
    Ball *ball = new Ball(ballConstraint, Game::data);
    ball->setPosition(leftEdge + width / 2 - ball->getBoundingBox().width / 2, 
                      topEdge + height / 2 - ball->getBoundingBox().height / 2);
    this->data->visibleObjectManager.addObject("ball", ball);

    Player *player1 = new Player(topEdge + 10, bottomEdge - 10, Game::data);
    player1->setPosition(leftEdge + 10, topEdge + height / 2 - player1->getBoundingBox().height / 2);
    this->data->visibleObjectManager.addObject("Player1", player1);

    Player *player2 = new Player(topEdge - 10, bottomEdge - 10, Game::data);
    player2->setPosition(rightEdge - player2->getBoundingBox().width - 10, topEdge + height / 2 - player2->getBoundingBox().height / 2);
    this->data->visibleObjectManager.addObject("Player2", player2);
    ////////////////////////////////////////////////////////////////////////////


    ///////////////////Initialize the scoring system////////////////////////////
    if (!this->scoreFont.loadFromFile("assets/fonts/Roboto-Bold.ttf")) {
      throw std::runtime_error("Failed to load score font");
    }
    this->scoreText1.setFont(this->scoreFont);
    this->scoreText1.setCharacterSize(100);
    this->scoreText1.setStyle(sf::Text::Bold);
    this->scoreText1.setFillColor(sf::Color(128, 128, 128, 100));
    this->scoreText1.setPosition(leftEdge + width / 2 - 105, topEdge + height / 2 - 65);
    this->scoreText1.setString("0");

    this->scoreText2.setFont(this->scoreFont);
    this->scoreText2.setCharacterSize(100);
    this->scoreText2.setStyle(sf::Text::Bold);
    this->scoreText2.setFillColor(sf::Color(128, 128, 128, 100));
    this->scoreText2.setPosition(leftEdge + width / 2 + 45, topEdge + height / 2 - 65);
    this->scoreText2.setString("0");
    ////////////////////////////////////////////////////////////////////////////


    return 0;
  }

  void TwoPlayerState::handleInput() {
    sf::Event event;
    while (this->data->window.pollEvent(event)) {
      if (event.type == sf::Event::Closed | sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->data->window.close();
      }
    }
  }

  void TwoPlayerState::update(float timeElapsed) {
  }
  
  void TwoPlayerState::endLoopLogic() {

  }

  void TwoPlayerState::render() {
    this->data->window.clear(sf::Color::White);
    this->data->visibleObjectManager.draw();
    this->data->window.draw(this->scoreText1);
    this->data->window.draw(this->scoreText2);
    this->data->window.display();
  }
}