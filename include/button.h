#ifndef WIGI_BUTTON_H
#define WIGI_BUTTON_H
#include "color.h"
#include "vector2.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Window/Mouse.hpp>

namespace wigi {
    class Button {
    public:
        Button(unsigned int width, unsigned int height);
        operator sf::RectangleShape() {
            return m_rect;
        }

        bool isClicked(sf::RenderWindow& win);
        bool isHeld(sf::RenderWindow& win);

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

    private:
        sf::RectangleShape m_rect;
        Vector2<float> m_size{1,1};
        Vector2<float> m_position{0,0};
        Color m_color{255,255,255};
        static sf::Mouse m_mouse;
        static bool m_wasMouseClicked;
    };
} // Namespace wigi

#endif //WIGI_BUTTON_H
