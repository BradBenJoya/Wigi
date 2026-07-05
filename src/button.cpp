#include "button.h"
#include <SFML/Window/Mouse.hpp>

namespace wigi {

    sf::Mouse Button::m_mouse;
    bool Button::m_wasMouseClicked = false;

    Button::Button(unsigned const int width, unsigned const int height) {
        m_rect.setFillColor(m_color);
        m_rect.setPosition(m_position);
        m_rect.setSize(m_size);
        m_rect.setOrigin(m_size / 2);
    }

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