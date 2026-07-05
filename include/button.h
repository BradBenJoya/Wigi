#ifndef WIGI_BUTTON_H
#define WIGI_BUTTON_H
#include "color.h"
#include "vector2.h"
#include "SFML/Graphics/RectangleShape.hpp"

namespace wigi {
    class Button {
    public:
        Button(unsigned int width, unsigned int height);
        operator sf::RectangleShape() {
            return m_rect;
        }

        bool isClicked() const;

        void setPosition(const Vector2<float>& position) {
            m_position = position;
        }

        Vector2<float> getPosition() const {
            return m_position;
        }

        void setColor(const Color& color) {
            m_color = color;
        }

        Color getColor() const {
            return m_color;
        }

        void setSize(Vector2<int> size) {
            m_size = size;
        }

        void setSize(int width, int height) {
            m_size = Vector2<int>(width, height);
        }

        Vector2<int> getSize() const {
            return m_size;
        }

    private:
        sf::RectangleShape m_rect;
        Vector2<int> m_size{1,1};
        Vector2<float> m_position{0,0};
        Color m_color{255,255,255};
    };
} // Namespace wigi

#endif //WIGI_BUTTON_H
