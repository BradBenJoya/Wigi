#include "button.h"
#include <SFML/Window/Mouse.hpp>

namespace wigi {

    void Button::setLabel(const std::string& text, sf::Font& font, unsigned int size) {
        m_font = &font;
        m_label.setFont(font);
        m_label.setString(text);
        m_label.setCharacterSize(size);
        m_label.setFillColor(sf::Color::White);

        // Centre the text origin so setPosition(m_position) keeps it centred on the button
        sf::FloatRect bounds = m_label.getLocalBounds();
        m_label.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    }

    void Button::update(sf::RenderWindow& win) {
        bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        m_hovered = isHovered(win);
        m_held = m_hovered && pressed;
        m_clicked = m_hovered && pressed && !m_wasMouseClicked;
        m_wasMouseClicked = pressed;
    }

    void Button::draw(sf::RenderWindow& win) const {
        Rectangle::draw(win);
        if (m_font) {
            m_label.setPosition(static_cast<sf::Vector2f>(m_position));
            win.draw(m_label);
        }
    }

    bool Button::isHovered(sf::RenderWindow& win) const {
        Vector2<int> mousePos = sf::Mouse::getPosition(win);
        Vector2<float> mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        return m_rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosF));
    }

} // namespace wigi