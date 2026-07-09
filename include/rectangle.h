#ifndef WIGI_RECTANGLE_H
#define WIGI_RECTANGLE_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "vector2.h"
#include "color.h"
namespace wigi {
    class Rectangle {
    public:
        Rectangle(unsigned int width = 1, unsigned int height = 1);

        operator sf::RectangleShape() {
            return m_rect;
        }

        void setPosition(const Vector2<float>& position) {
            m_position = position;
            m_rect.setPosition(m_position);
        }

        Vector2<float> getPosition() const {
            return m_position;
        }

        void setColor(const Color& color) {
            m_color = color;
            m_rect.setFillColor(m_color);
        }

        Color getColor() const {
            return m_color;
        }

        void setSize(Vector2<float> size) {
            m_size = size;
            m_rect.setSize(size);
            m_rect.setOrigin(m_size / 2);
        }

        void setSize(float width, float height) {
            m_size = Vector2<float>(width, height);
            m_rect.setSize(m_size);
            m_rect.setOrigin(m_size / 2);
        }

        Vector2<float> getSize() const {
            return m_size;
        }

    protected:
        sf::RectangleShape m_rect;
        Vector2<float> m_size{1,1};
        Vector2<float> m_position{0,0};
        Color m_color{255,255,255};
    };
}
#endif //WIGI_RECTANGLE_H
