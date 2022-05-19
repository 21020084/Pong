#include "../Game.h"
#include "Menu-state.h"
#include "../objects/gui/exit-button.h"
#include "../objects/gui/one-player-button.h"
#include "../objects/gui/two-player-button.h"

namespace pong {
  MenuState::MenuState(GameDataRef _data) : GameState(_data) {
    this->m_ID = Menu;
  }

  int MenuState::init() {

    if (!m_backgroundTexture.loadFromFile("assets/m_background.png")) {
      std::cout << "Error loading menu background" << std::endl;
      return -1;
    }
    m_backgroundSprite.setTexture(m_backgroundTexture);

    /// Add buttons to the menu
    OnePlayerButton *onePlayerButton = new OnePlayerButton(this->data);
    onePlayerButton->setPosition(390, 400);
    this->data->visibleObjectManager.addObject("M_onePlayerButton", onePlayerButton);

    TwoPlayerButton *twoPlayerButton = new TwoPlayerButton(this->data);
    twoPlayerButton->setPosition(390, 550);
    this->data->visibleObjectManager.addObject("M_twoPlayerButton", twoPlayerButton);

    ExitButton *exitButton = new ExitButton(this->data);
    exitButton->setPosition(390, 700);
    this->data->visibleObjectManager.addObject("M_exitButton", exitButton);

    return 0;
  }

  void MenuState::handleInput() {
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
    this->data->visibleObjectManager.handleInput(event, 'M');
    this->data->cursor.loadFromSystem(VisibleObject::CursorType);
    this->data->window.setMouseCursor(this->data->cursor);
  }
  
  void MenuState::update(float timeElapsed) {
    this->data->visibleObjectManager.update(timeElapsed, 'M');
  }

  void MenuState::render() {
    this->data->window.draw(m_backgroundSprite);
    this->data->visibleObjectManager.draw('M');
    this->data->window.display();
  }
}