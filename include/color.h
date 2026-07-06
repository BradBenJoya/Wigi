#ifndef WIGI_COLOR_H
#define WIGI_COLOR_H
#include <cstdint>
#include <SFML/Graphics/Color.hpp>

namespace wigi {
    struct Color {
        using uint8 = std::uint8_t;
        uint8 r = 0;
        uint8 g = 0;
        uint8 b = 0;
        uint8 a = 255;

        Color() = default;

        Color(const uint8 r, const uint8 g, const uint8 b, const uint8 a = 255) : r(r), g(g), b(b), a(a) {}

        Color(const sf::Color& c) : r(c.r), g(c.g), b(c.b), a(c.a) {}

        operator sf::Color() const {
            return sf::Color(r, g, b, a);
        }

        // Comparison
        bool operator==(const Color& c) const {
            return r == c.r && g == c.g && b == c.b && a == c.a;
        }

        bool operator!=(const Color& c) const {
            return !(*this == c);
        }

    };
} // Namespace wigi

#endif //WIGI_COLOR_H