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
        bool isClicked(sf::RenderWindow& win);
        bool isHeld(sf::RenderWindow& win);

    protected:
        static sf::Mouse m_mouse;
        static bool m_wasMouseClicked;

        bool isHovered(sf::RenderWindow& win) const {
            Vector2<int> mousePos = sf::Mouse::getPosition(win);
            Vector2 mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            return m_rect.getGlobalBounds().contains(mousePosF);
        }
    };
} // Namespace wigi

#endif //WIGI_BUTTON_H
