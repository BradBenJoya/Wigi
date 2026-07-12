#ifndef WIGI_WINDOW_H
#define WIGI_WINDOW_H
#include "SFML/Graphics/RenderWindow.hpp"
#include <string_view>
#include <string>
#include <functional>

#include "color.h"

namespace wigi {
    class Window {
        public:
            Window(unsigned int width, unsigned int height, std::string_view title);

            void run(const std::function<void(sf::RenderWindow&)>& on_frame);

            bool isOpen() const noexcept {
                return m_window.isOpen();
            }

            Color backgroundColor{0,0,0};

        private:
            sf::RenderWindow m_window;

            unsigned int m_width{0u};
            unsigned int m_height{0u};

            std::string m_title;
    };
} // namespace wigi

#endif //WIGI_WINDOW_H
