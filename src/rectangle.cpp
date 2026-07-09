#include "rectangle.h"

namespace wigi {
    Rectangle::Rectangle(unsigned int width, unsigned int height) {
        m_size = {static_cast<float>(width), static_cast<float>(height)};
        m_rect.setFillColor(m_color);
        m_rect.setPosition(m_position);
        m_rect.setSize(m_size);
        m_rect.setOrigin(m_size / 2);
    }
}
