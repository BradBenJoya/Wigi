#ifndef WIGI_VECTOR2_H
#define WIGI_VECTOR2_H

namespace wigi {
    template <typename T>
    struct Vector2 {
        Vector2() = default;
        Vector2(T x, T y) : x(x), y(y) {}
        T x, y;
    };
}

#endif //WIGI_VECTOR2_H
