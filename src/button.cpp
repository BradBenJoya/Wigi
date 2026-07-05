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
        Vector2<int> mousePos = sf::Mouse::getPosition(win);
        Vector2 mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        bool hovering = m_rect.getGlobalBounds().contains(mousePosF);
        bool isPressedNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);

        bool justClicked = hovering && isPressedNow && !m_wasMouseClicked;

        m_wasMouseClicked = isPressedNow;

        return justClicked;
    }

    bool Button::isHeld(sf::RenderWindow &win) {
        Vector2<int> mousePos = sf::Mouse::getPosition(win);
        Vector2 mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        if (m_rect.getGlobalBounds().contains(mousePosF) && m_mouse.isButtonPressed(sf::Mouse::Left)) {
            return true;
        }
        return false;
    }
} // Namespace wigi