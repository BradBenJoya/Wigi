#include <iostream>
#include "window.h"

using namespace std;

int main() {
	wigi::Window window(800, 600, "Wigi");
	window.backgroundColor = {0,0,255};
	window.run([&](sf::RenderWindow& win) {
	});
	return 0;
}