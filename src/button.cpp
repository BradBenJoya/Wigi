#include "button.h"
#include <SFML/Window/Mouse.hpp>

namespace wigi {

    sf::Mouse Button::m_mouse;
    bool Button::m_wasMouseClicked = false;

    bool Button::isClicked(sf::RenderWindow& win) {
        bool isPressedNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);

        bool justClicked = isHovered(win) && isPressedNow && !m_wasMouseClicked;

        m_wasMouseClicked = isPressedNow;

        return justClicked;
    }

    bool Button::isHeld(sf::RenderWindow &win) {
        if (isHovered(win) && m_mouse.isButtonPressed(sf::Mouse::Left)) {
            return true;
        }
        return false;
    }
} // Namespace wigi