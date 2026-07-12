#ifndef WIGI_BUTTON_H
#define WIGI_BUTTON_H
#include "rectangle.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"
#include <SFML/Window/Mouse.hpp>
#include <string>

namespace wigi {
    class Button : public Rectangle {
    public:
        using Rectangle::Rectangle;

        void setLabel(const std::string& text, sf::Font& font, unsigned int size = 16);

        void update(sf::RenderWindow& win);
        void draw(sf::RenderWindow& win) const;

        bool isClicked() const { return m_clicked; }
        bool isHeld() const { return m_held; }
        bool isHovered() const { return m_hovered; }
        bool isHovered(sf::RenderWindow& win) const;

    protected:
        mutable bool m_wasMouseClicked{false};

    private:
        bool m_clicked{false};
        bool m_held{false};
        bool m_hovered{false};

        sf::Font* m_font{nullptr};
        mutable sf::Text m_label{};
    };
} // namespace wigi
#endif //WIGI_BUTTON_H
