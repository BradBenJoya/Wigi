#ifndef WIGI_DROPDOWN_H
#define WIGI_DROPDOWN_H

#include "button.h"
#include <vector>
#include <functional>

namespace wigi {
    class Dropdown : public Button {
    public:
        Dropdown(unsigned int width, unsigned int height);

        void addButton(const Button& button);

        void setPosition(const Vector2<float>& position);
        void setSize(Vector2<float> size);
        void setSize(float width, float height);

        void update(sf::RenderWindow& win);
        void draw(sf::RenderWindow& win) const;

        void onSelect(std::function<void(int)> callback) { m_onSelect = std::move(callback); }
        int getSelectedItem() const { return m_selectedIndex; }
        void clearSelection() { m_selectedIndex = -1; }

        std::vector<Button>& getItems() { return items; }
        const std::vector<Button>& getItems() const { return items; }

    private:
        std::vector<Button> items{};
        mutable bool m_isOpen{false};
        int m_selectedIndex{-1};
        std::function<void(int)> m_onSelect;
    };
}

#endif //WIGI_DROPDOWN_H
