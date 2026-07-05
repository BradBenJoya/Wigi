#ifndef WIGI_COLOR_H
#define WIGI_COLOR_H
#include <cstdint>
#include <SFML/Graphics/Color.hpp>

namespace wigi {
    struct Color {
        using uint8 = std::uint8_t;
        uint8 r;
        uint8 g;
        uint8 b;

        Color() = default;

        Color(const uint8 r, const uint8 g, const uint8 b) : r(r), g(g), b(b) {}

        operator sf::Color() const {
            return sf::Color(r, g, b);
        }
    };
} // Namespace wigi

#endif //WIGI_COLOR_H
