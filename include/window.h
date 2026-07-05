#ifndef WIGI_WINDOW_H
#define WIGI_WINDOW_H
#include "SFML/Graphics/RenderWindow.hpp"
#include <string_view>
#include <string>
#include <functional>

namespace wigi {
    class Window {
        public:
            Window(unsigned const int  width, unsigned const int height, const std::string_view title);

            const bool isOpen() const {
                return m_window.isOpen();
            }

            void run(const std::function<void(sf::RenderWindow&)>& on_frame);

        private:
            sf::RenderWindow m_window;

            unsigned int m_width{0u};
            unsigned int m_height{0u};

            std::string m_title;
    };
} // namespace wigi

#endif //WIGI_WINDOW_H
