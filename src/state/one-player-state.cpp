#include <stdexcept>
#include <thread>

#include "one-player-state.h"
#include "../objects/visible-object.h"
#include "../objects/entities/field.h"
#include "../objects/entities/ball.h"
#include "../objects/entities/player.h"
#include "../Game.h"
#include "../DEFINITION.h"

namespace pong {
  OnePlayerState::OnePlayerState(GameDataRef _data) : GameState(_data) {
    this->score1 = 0;
    this->score2 = 0;
    this->m_ID = OnePlayer;
  }

  OnePlayerState::~OnePlayerState() {
    this->data->visibleObjectManager.removeObject("O_Field");
    this->data->visibleObjectManager.removeObject("O_Player1");
    this->data->visibleObjectManager.removeObject("O_Player2");
    this->data->visibleObjectManager.removeObject("O_ball");
  }

  int OnePlayerState::init() {

    this->data->cursor.loadFromSystem(sf::Cursor::Arrow);
    this->data->window.setMouseCursor(this->data->cursor);
    // /// Remove all objects of the previous state
    // this->data->visibleObjectManager.clearObjects();


    /*******************Initialize the game objects****************************/
    Field *field = new Field(Game::data);
    field->setPosition(0, 0);
    /// Object added to the visible object manager
    this->data->visibleObjectManager.addObject("O_Field", field);

    ////////////////////////////////////////////////////////////////////////////
    float leftEdge = field->getLeft();
    float rightEdge = field->getRight();
    float topEdge = field->getTop();
    float bottomEdge = field->getBottom();

    float width = rightEdge - leftEdge;
    float height = bottomEdge - topEdge;
    ////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////Left player///////////////////////////////
    Player *player1 = new Player(topEdge + 10, bottomEdge - 10, true, Game::data);
    player1->setPosition(leftEdge + 10, topEdge + height / 2 - player1->getBoundingBox().height / 2);
    /// Player1 is controlled by the computer 
    player1->setAI(true);
    /// Object added to the visible object manager
    this->data->visibleObjectManager.addObject("O_Player1", player1);
    ////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////Right player///////////////////////////////
    Player *player2 = new Player(topEdge - 10, bottomEdge - 10, false, Game::data);
    player2->setPosition(rightEdge - player2->getBoundingBox().width - 10, 
                        topEdge + height / 2 - player2->getBoundingBox().height / 2);
    /// Object added to the visible object manager
    this->data->visibleObjectManager.addObject("O_Player2", player2);
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    sf::FloatRect ballConstraint = sf::FloatRect(leftEdge, topEdge, width, height);
    Ball *ball = new Ball(ballConstraint, Game::data);
    /// Set default position of the ball
    ball->resetPosition(player1, player2);
    /// Object added to the visible object manager
    this->data->visibleObjectManager.addObject("O_ball", ball);
    ////////////////////////////////////////////////////////////////////////////

    /**************************************************************************/


    /******************Initialize the scoring system***************************/
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
    /**************************************************************************/

    return 0;
  }

  void OnePlayerState::handleInput() {
    sf::Event event;
    while (this->data->window.pollEvent(event)) {
      /// Check if the user wants to close the window
      if (event.type == sf::Event::Closed) {
        this->data->window.close();
      }
      /// Check if the user wants to pause the game
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        this->data->stateManager.addState(Pause);
      }
      this->data->visibleObjectManager.handleInput(event, 'O');
    }
  }

  static int debug = 0;

  void OnePlayerState::handleTurnChanging() {
    /******* Reset ball position if it is out of the field *******/    
    Ball *ball = dynamic_cast<Ball*> (this->data->visibleObjectManager.getObject("O_ball"));
    if (!ball) {
      throw std::runtime_error("Ball not found");
    }
    if (!ball->isOut()) return;

    if (ball->collidedWith == Ball::CollidedWith::RIGHT) {
      this->score2++;
      this->scoreText2.setString(std::to_string(this->score2));
      // std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
      ball->resetPosition(this->data->visibleObjectManager.getObject("O_Player1"),
                          this->data->visibleObjectManager.getObject("O_Player2"));
    } else {
      this->score1++;
      if (score1 == 1)
        debug = 1;
      this->scoreText1.setString(std::to_string(this->score1));
      // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      ball->resetPosition(this->data->visibleObjectManager.getObject("O_Player1"),
                          this->data->visibleObjectManager.getObject("O_Player2"));
    }
    ball->setOut(false);
    ball->addSpeed(0.5f);
    ball->resetFreezeTimer();
    /// Reload the angle of the ball
    if (ball->collidedWith == Ball::CollidedWith::RIGHT) {
      ball->setAngle(1.0f * (rand() % 161) + 100.f);
    } else {
      ball->setAngle(1.0f * (rand() % 161) - 80.0f);
    }
    /***********************************************************/


    /*********** Reset and update player ***********/
    Player *player1 = dynamic_cast<Player*> (this->data->visibleObjectManager.getObject("O_Player1"));
    if (!player1) {
      throw std::runtime_error("Player1 not found");
    }
    player1->resetFreezeTimer();

    Player *player2 = dynamic_cast<Player*> (this->data->visibleObjectManager.getObject("O_Player2"));
    if (!player2) {
      throw std::runtime_error("Player1 not found");
    }
    player2->resetFreezeTimer();

    if (ball->getSpeed()  - this->ballSpeed >= 5.0f) {
      this->ballSpeed = ball->getSpeed();
      player1->addSpeed(0.6f);
      player2->addSpeed(0.6f);
    }
    /************************************************/

    std::this_thread::sleep_for(std::chrono::milliseconds(1550));
  }

  void OnePlayerState::update(float timeElapsed) {
    this->data->visibleObjectManager.update(timeElapsed, 'O');

    this->handleTurnChanging();

    this->scoreText1.setString(std::to_string(this->score1));
    this->scoreText2.setString(std::to_string(this->score2));
  }

  void OnePlayerState::render() {
    this->data->window.clear(sf::Color::White);
    this->data->visibleObjectManager.draw('O');
    this->data->window.draw(this->scoreText1);
    this->data->window.draw(this->scoreText2);
    this->data->window.display();
  }
}