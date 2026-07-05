#include <iostream>
#include "window.h"

using namespace std;

int main()
{
	wigi::Window window(1920, 1080, "Wigi");
	window.run([&](sf::RenderWindow& win) {
	   
	});
	return 0;
}