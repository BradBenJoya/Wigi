#ifndef WIGI_RECTANGLE_H
#define WIGI_RECTANGLE_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "vector2.h"
#include "color.h"

namespace wigi {
    class Rectangle {
    public:
        Rectangle(unsigned int width = 1, unsigned int height = 1);
        virtual ~Rectangle() = default;

        operator const sf::RectangleShape&() const {
            return m_rect;
        }

        operator sf::RectangleShape&() {
            return m_rect;
        }

        virtual void setPosition(const Vector2<float>& position) {
            m_position = position;
            m_rect.setPosition(static_cast<sf::Vector2f>(m_position));
        }

        Vector2<float> getPosition() const noexcept {
            return m_position;
        }

        void setColor(const Color& color) {
            m_color = color;
            m_rect.setFillColor(m_color);
        }

        Color getColor() const noexcept {
            return m_color;
        }

        virtual void setSize(Vector2<float> size) {
            m_size = size;
            m_rect.setSize(static_cast<sf::Vector2f>(size));
            m_rect.setOrigin(static_cast<sf::Vector2f>(m_size / 2.0f));
        }

        virtual void setSize(float width, float height) {
            m_size = Vector2<float>(width, height);
            m_rect.setSize(static_cast<sf::Vector2f>(m_size));
            m_rect.setOrigin(static_cast<sf::Vector2f>(m_size / 2.0f));
        }

        Vector2<float> getSize() const noexcept {
            return m_size;
        }

    protected:
        void draw(sf::RenderWindow& target) const {
            target.draw(m_rect);
        }

        sf::RectangleShape m_rect;
        Vector2<float> m_size{1.0f, 1.0f};
        Vector2<float> m_position{0.0f, 0.0f};
        Color m_color{255, 255, 255};
    };
}
#endif //WIGI_RECTANGLE_H
