#include "Menu-state.h"

namespace pong {
  MenuState::MenuState(GameDataRef _data) : data(_data) {}

  int MenuState::init() {
    if (!m_backgroundTexture.loadFromFile("assets/m_background.png")) {
      std::cout << "Error loading menu background" << std::endl;
      return -1;
    }

    if (!onePlayerTexture.loadFromFile("assets/one_player.png")) {
      std::cout << "Error loading one player button" << std::endl;
      return -1;
    }

    if (!twoPlayerTexture.loadFromFile("assets/two_player.png")) {
      std::cout << "Error loading two player button" << std::endl;
      return -1;
    }
    return 0;
  }

  void MenuState::handleInput() {};
  void MenuState::update(float timeElapsed) {};

  void MenuState::render() {
    data->window.draw(m_backgroundSprite);
    // data->window.draw(onePlayerSprite);
    // data->window.draw(twoPlayerSprite);
    // data->window.draw(exitSprite);
    data->window.display();
  }
}