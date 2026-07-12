#include "dropdown.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Window/Mouse.hpp>

namespace wigi {

    Dropdown::Dropdown(unsigned int width, unsigned int height)
        : Button(width, height) {
        setColor({60, 60, 60});
    }

    void Dropdown::addButton(const Button& button) {
        Button newButton = button;
        newButton.setSize(getSize());

        float offset = (static_cast<float>(items.size()) + 1.f) * getSize().y;
        newButton.setPosition({getPosition().x, getPosition().y + offset});

        items.push_back(newButton);
    }

    void Dropdown::setPosition(const Vector2<float>& position) {
        Button::setPosition(position);
        for (size_t i = 0; i < items.size(); i++) {
            items[i].setPosition({position.x, position.y + static_cast<float>(i + 1) * getSize().y});
        }
    }

    void Dropdown::setSize(Vector2<float> size) {
        Button::setSize(size);
        for (size_t i = 0; i < items.size(); i++) {
            items[i].setSize(size);
            items[i].setPosition({getPosition().x, getPosition().y + static_cast<float>(i + 1) * size.y});
        }
    }

    void Dropdown::setSize(float width, float height) {
        setSize(Vector2<float>(width, height));
    }

    void Dropdown::update(sf::RenderWindow& win) {
        bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        bool justClicked = pressed && !m_wasMouseClicked;
        m_wasMouseClicked = pressed;

        if (!justClicked) return;

        if (isHovered(win)) {
            m_isOpen = !m_isOpen;
        } else if (m_isOpen) {
            for (size_t i = 0; i < items.size(); ++i) {
                if (items[i].isHovered(win)) {
                    m_selectedIndex = static_cast<int>(i);
                    if (m_onSelect) m_onSelect(m_selectedIndex);
                    break;
                }
            }
            m_isOpen = false;
        }
    }

    void Dropdown::draw(sf::RenderWindow& win) const {
        Button::draw(win);

        if (m_isOpen) {
            for (const auto& item : items) {
                item.draw(win);
            }
        }
    }

}
