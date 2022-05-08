#include "Menu-state.h"
#include "../Game.h"

namespace pong {
  MenuState::MenuState(GameDataRef _data) : GameState(_data) {}

  int MenuState::init() {
    if (!m_backgroundTexture.loadFromFile("assets/m_background.png")) {
      std::cout << "Error loading menu background" << std::endl;
      return -1;
    }
    m_backgroundSprite.setTexture(m_backgroundTexture);

    // if (!onePlayerTexture.loadFromFile("assets/one_player.png")) {
    //   std::cout << "Error loading one player button" << std::endl;
    //   return -1;
    // }

    // if (!twoPlayerTexture.loadFromFile("assets/two_player.png")) {
    //   std::cout << "Error loading two player button" << std::endl;
    //   return -1;
    // }
    return 0;
  }

  void MenuState::handleInput() {
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
  };
  
  void MenuState::update(float timeElapsed) {};

  void MenuState::render() {
    // this->data->window.clear(sf::Color::Black);
    this->data->window.draw(this->m_backgroundSprite);
    // data->window.draw(onePlayerSprite);
    // data->window.draw(twoPlayerSprite);
    // data->window.draw(exitSprite);
    this->data->window.display();
  }
}