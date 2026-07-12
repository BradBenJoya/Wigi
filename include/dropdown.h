#ifndef WIGI_DROPDOWN_H
#define WIGI_DROPDOWN_H

#include "button.h"
#include <vector>

namespace wigi {
    class Dropdown : public Button {
    public:
        Dropdown(unsigned int width, unsigned int height);

        void addButton(const Button& button);

        void setPosition(const Vector2<float>& position);
        void setSize(Vector2<float> size);
        void setSize(float width, float height);

        std::vector<Button>& getItems() { return m_items; }
        const std::vector<Button>& getItems() const { return m_items; }

        mutable int currentItem{-1};

    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        std::vector<Button> m_items{};
        mutable bool m_isOpen{false};
        mutable int m_selectedIndex{-1};
    };
}

#endif //WIGI_DROPDOWN_H
