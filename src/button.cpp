#include "button.h"
#include <SFML/Window/Mouse.hpp>

namespace wigi {

    bool Button::isClicked(sf::RenderWindow& win) const {
        bool isPressedNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);

        bool justClicked = isHovered(win) && isPressedNow && !m_wasMouseClicked;

        m_wasMouseClicked = isPressedNow;

        return justClicked;
    }

    bool Button::isHeld(sf::RenderWindow &win) const {
        if (isHovered(win) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return true;
        }
        return false;
    }
} // Namespace wigi