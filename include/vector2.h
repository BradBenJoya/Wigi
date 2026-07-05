#ifndef WIGI_VECTOR2_H
#define WIGI_VECTOR2_H
#include "SFML/System/Vector2.hpp"

namespace wigi {
    template <typename T>
    struct Vector2 {
        Vector2() = default;
        Vector2(T x, T y) : x(x), y(y) {}
        T x, y;
        operator sf::Vector2<T>() { return sf::Vector2<T>(x, y); }
    };
}

#endif //WIGI_VECTOR2_H
