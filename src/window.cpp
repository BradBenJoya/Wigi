#include "window.h"
#include <SFML/Window/Event.hpp>

namespace wigi {
    Window::Window(unsigned const int  width, unsigned const int height, const std::string_view title) {
        m_width = width;
        m_height = height;
        m_title = title;

        m_window.create(sf::VideoMode(m_width, m_height), m_title);
    }

    void Window::run(const std::function<void(sf::RenderWindow&)>& on_frame) {
        while (isOpen()) {
            sf::Event event;
            while (m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    m_window.close();
                }
            }

            m_window.clear(sf::Color(backgroundColor.r, backgroundColor.g, backgroundColor.b));
            on_frame(m_window);
            m_window.display();
        }
    }
}