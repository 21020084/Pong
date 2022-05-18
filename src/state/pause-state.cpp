#include "../Game.h"
#include "pause-state.h"
#include "../objects/gui/exit-button.h"
#include "../objects/gui/one-player-button.h"
#include "../objects/gui/two-player-button.h"

namespace pong {
  PauseState::PauseState(GameDataRef _data) : GameState(_data) {}

  int PauseState::init() {
    if (!m_backgroundTexture.loadFromFile("assets/pause.png")) {
      std::cout << "Error loading Pause background" << std::endl;
      return -1;
    }
    m_backgroundSprite.setTexture(m_backgroundTexture);

    /// Add buttons to the Pause
    OnePlayerButton *onePlayerButton = new OnePlayerButton(this->data);
    onePlayerButton->setPosition(390, 400);
    this->data->visibleObjectManager.addObject("onePlayerButton", onePlayerButton);

    TwoPlayerButton *twoPlayerButton = new TwoPlayerButton(this->data);
    twoPlayerButton->setPosition(390, 550);
    this->data->visibleObjectManager.addObject("twoPlayerButton", twoPlayerButton);

    ExitButton *exitButton = new ExitButton(this->data);
    exitButton->setPosition(390, 700);
    this->data->visibleObjectManager.addObject("exitButton", exitButton);

    return 0;
  }

  void PauseState::handleInput() {
    VisibleObject::CursorType = sf::Cursor::Arrow;

    /// Check if the user want to quit the game
    sf::Event event;
    while (this->data->window.pollEvent(event)) {
      /// If the user wants to quit the game
      if (event.type == sf::Event::Closed ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->m_hasClosed  = true;
        this->data->window.close();
      }
    }

    /// Check if the user clicked on the buttons
    this->data->visibleObjectManager.handleInput(event);
    this->data->cursor.loadFromSystem(VisibleObject::CursorType);
    this->data->window.setMouseCursor(this->data->cursor);
  }
  
  void PauseState::update(float timeElapsed) {
    this->data->visibleObjectManager.update(timeElapsed);
  }

  void PauseState::render() {
    this->data->window.draw(m_backgroundSprite);
    this->data->visibleObjectManager.draw();
    this->data->window.display();
  }
}