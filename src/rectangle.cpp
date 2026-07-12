#include "rectangle.h"

namespace wigi {
    Rectangle::Rectangle(unsigned int width, unsigned int height) {
        m_size = {static_cast<float>(width), static_cast<float>(height)};
        m_rect.setFillColor(m_color);
        m_rect.setPosition(static_cast<sf::Vector2f>(m_position));
        m_rect.setSize(static_cast<sf::Vector2f>(m_size));
        m_rect.setOrigin(static_cast<sf::Vector2f>(m_size / 2.0f));
    }
}
