#ifndef WIGI_BUTTON_H
#define WIGI_BUTTON_H
#include "color.h"
#include "SFML/Graphics/RectangleShape.hpp"

namespace wigi {
    class Button {
    public:
        Button(unsigned int width, unsigned int height);

        bool isClicked() const;

    private:
        sf::RectangleShape m_rect;
        unsigned int m_width{1}, m_height{1};
        Color m_color{255,255,255};
    };
} // Namespace wigi

#endif //WIGI_BUTTON_H
