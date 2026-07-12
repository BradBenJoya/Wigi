#ifndef WIGI_BUTTON_H
#define WIGI_BUTTON_H
#include "vector2.h"
#include "rectangle.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Window/Mouse.hpp>

namespace wigi {
    class Button : public Rectangle {
    public:
        using Rectangle::Rectangle;
        bool isClicked(sf::RenderWindow& win) const;
        bool isHeld(sf::RenderWindow& win) const;

        bool isHovered(sf::RenderWindow& win) const {
            Vector2<int> mousePos = sf::Mouse::getPosition(win);
            Vector2<float> mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            return m_rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosF));
        }

    protected:
        mutable bool m_wasMouseClicked{false};
    };
} // Namespace wigi
#endif //WIGI_BUTTON_H
