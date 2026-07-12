#include "window.h"
#include "button.h"
#include "dropdown.h"
#include <iostream>

int main() {
    wigi::Window window(800, 600, "Wigi");

    wigi::Dropdown dropdown{150, 50};
    dropdown.setPosition({400, 300});

    wigi::Button item1;
    dropdown.addButton(item1);

    wigi::Button item2;
    dropdown.addButton(item2);
    item2.setColor({0,0,255});

    window.run([&](sf::RenderWindow& win) {
       win.draw(dropdown);

       if (dropdown.currentItem != -1) {
           std::cout << "Selected index: " << dropdown.currentItem << std::endl;
           dropdown.currentItem = -1;
       }
    });

    return 0;
}