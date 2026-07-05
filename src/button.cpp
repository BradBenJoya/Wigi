#include "button.h"

namespace wigi {
    Button::Button(unsigned const int width, unsigned const int height) {
        m_width = width;
        m_height = height;

        m_rect.setFillColor(m_color);
        m_rect.setPosition(m_position);
    }
} // Namespace wigi