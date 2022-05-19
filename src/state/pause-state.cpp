#include "../Game.h"
#include "pause-state.h"
#include "../objects/gui/resume-button.h"
#include "../objects/gui/mainMenu-button.h"

namespace pong {
  PauseState::PauseState(GameDataRef _data) : GameState(_data) {
    this->m_ID = Pause;
  }

  int PauseState::init() {
    if (!m_backgroundTexture.loadFromFile("assets/pause.png")) {
      std::cout << "Error loading Pause background" << std::endl;
      return -1;
    }
    m_backgroundSprite.setTexture(m_backgroundTexture);

    /// Add buttons to the Pause
    ResumeButton *resumeButton = new ResumeButton(this->data);
    resumeButton->setPosition(390, 450);
    this->data->visibleObjectManager.addObject("P_resumeButton", resumeButton);

    MainMenuButton *mainMenuButton = new MainMenuButton(this->data);
    mainMenuButton->setPosition(390, 600);
    this->data->visibleObjectManager.addObject("P_mainMenuButton", mainMenuButton);

    return 0;
  }

  void PauseState::handleInput() {
    VisibleObject::CursorType = sf::Cursor::Arrow;

    /// Check if the user want to quit the game
    sf::Event event;
    while (this->data->window.pollEvent(event)) {
      /// If the user wants to quit the game
      if (event.type == sf::Event::Closed) {
        this->m_hasClosed  = true;
        this->data->window.close();
        continue;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->m_hasClosed  = true;
        this->data->stateManager.closeCurrentState();
        continue;
      }
    }

    /// Check if the user clicked on the buttons
    this->data->visibleObjectManager.handleInput(event, 'P');
    this->data->cursor.loadFromSystem(VisibleObject::CursorType);
    this->data->window.setMouseCursor(this->data->cursor);
  }
  
  void PauseState::update(float timeElapsed) {
    this->data->visibleObjectManager.update(timeElapsed, 'P');
  }

  void PauseState::render() {
    this->data->window.clear();
    this->data->window.draw(m_backgroundSprite);
    this->data->visibleObjectManager.draw('P');
    this->data->window.display();
  }
}