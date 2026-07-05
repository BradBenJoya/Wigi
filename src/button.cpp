#include "button.h"

namespace wigi {
    Button::Button(unsigned int width, unsigned int height) {
        m_width = width;
        m_height = height;

        m_rect.setFillColor(sf::Color(m_color.r, m_color.g, m_color.b));
    }
} // Namespace wigi