#include "dropdown.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace wigi {
    Dropdown::Dropdown(unsigned int width, unsigned int height) 
        : Button(width, height) {
        setColor({60, 60, 60});
    }

    void Dropdown::addButton(const Button& button) {
        Button newButton = button;
        newButton.setSize(getSize());
        
        float offset = static_cast<float>((static_cast<float>(m_items.size()) + 1) * getSize().y);
        newButton.setPosition({getPosition().x, getPosition().y + offset});
        
        m_items.push_back(newButton);
    }

    void Dropdown::setPosition(const Vector2<float>& position) {
        Button::setPosition(position);
        for (unsigned int i = 0; i < m_items.size(); i++) {
            m_items[i].setPosition({position.x, position.y + static_cast<float>((static_cast<float>(i + 1)) * getSize().y)});
        }
    }

    void Dropdown::setSize(Vector2<float> size) {
        Button::setSize(size);
        for (unsigned int i = 0; i < m_items.size(); i++) {
            m_items[i].setSize(size);
            m_items[i].setPosition({getPosition().x, getPosition().y + static_cast<float>((static_cast<float>(i + 1)) * size.y)});
        }
    }

    void Dropdown::setSize(float width, float height) {
        setSize(Vector2<float>(width, height));
    }

    void Dropdown::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        Button::draw(target, states);

        auto* windowPtr = dynamic_cast<sf::RenderWindow*>(&target);
        if (windowPtr) {
            bool isPressedNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);
            bool clickOccurred = isPressedNow && !m_wasMouseClicked;
            m_wasMouseClicked = isPressedNow;

            if (clickOccurred) {
                if (isHovered(*windowPtr)) {
                    m_isOpen = !m_isOpen;
                } else if (m_isOpen) {
                    bool clickedAnyItem = false;
                    for (size_t i = 0; i < m_items.size(); ++i) {
                        if (m_items[i].isHovered(*windowPtr)) {
                            m_selectedIndex = static_cast<int>(i);
                            currentItem = static_cast<int>(i);
                            clickedAnyItem = true;
                            break;
                        }
                    }
                    m_isOpen = false;
                }
            }
        }

        if (m_isOpen) {
            for (const auto& item : m_items) {
                target.draw(item, states);
            }
        }
    }
}
