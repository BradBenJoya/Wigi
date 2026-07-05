#include "window.h"
#include "button.h"
#include <iostream>

using namespace std;

int main() {
	wigi::Window window(800, 600, "Wigi");

	window.backgroundColor = {0,0,255};

	wigi::Button button{200,200};

	button.setColor(wigi::Color(255,255,255));

	button.setPosition(wigi::Vector2<float>(400,300));

	button.setSize(wigi::Vector2<float>(400,400));

	window.run([&](sf::RenderWindow& win) {
		win.draw(button);
		if (button.isClicked(win)) {
			std::cout << "Clicked" << std::endl;
		}
	});

	return 0;
}