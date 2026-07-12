#include "window.h"
#include "button.h"
#include "dropdown.h"

int main() {
    wigi::Window window(800, 600, "Wigi");

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arial.ttf");

    wigi::Dropdown dropdown{150, 50};
    dropdown.setPosition({400, 300});
    dropdown.setLabel("Select...", font);

    wigi::Button item1;
    item1.setColor({80, 80, 80});
    item1.setLabel("Option 1", font);
    dropdown.addButton(item1);

    wigi::Button item2;
    item2.setColor({0, 0, 200});
    item2.setLabel("Option 2", font);
    dropdown.addButton(item2);

    wigi::Button item3;
    item3.setColor({200, 200, 200});
    item3.setLabel("Option 3", font);
    dropdown.addButton(item3);

    dropdown.onSelect([&](int i) {
        if (i == 0) {
            dropdown.setPosition({400, 300});
        } else if (i == 1) {
            dropdown.setPosition({300, 300});
        } else if (i == 2) {
            dropdown.setPosition({500, 300});
        }
    });

    window.run([&](sf::RenderWindow& win) {
        dropdown.update(win);
        dropdown.draw(win);
    });

    return 0;
}