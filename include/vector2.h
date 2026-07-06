#ifndef WIGI_VECTOR2_H
#define WIGI_VECTOR2_H
#include "SFML/System/Vector2.hpp"
#include <ostream>

namespace wigi {
    template <typename T>
    struct Vector2 {
        Vector2() = default;
        Vector2(T x, T y) : x(x), y(y) {}
        Vector2(const sf::Vector2<T>& v) : x(v.x), y(v.y) {}

        T x, y;

        operator sf::Vector2<T>() const {
            return sf::Vector2<T>(x, y);
        }

        // Arithmetic (vector-vector)
        Vector2 operator+(const Vector2& v) const {
            return Vector2(x + v.x, y + v.y);
        }

        Vector2 operator-(const Vector2& v) const {
            return Vector2(x - v.x, y - v.y);
        }

        Vector2 operator*(const Vector2& v) const {
            return Vector2(x * v.x, y * v.y);
        }

        Vector2 operator/(const Vector2& v) const {
            return Vector2(x / v.x, y / v.y);
        }

        // Arithmetic (vector-scalar)
        Vector2 operator*(T scalar) const {
            return Vector2(x * scalar, y * scalar);
        }

        Vector2 operator/(T scalar) const {
            return Vector2(x / scalar, y / scalar);
        }

        // Unary
        Vector2 operator-() const {
            return Vector2(-x, -y);
        }

        Vector2 operator+() const {
            return Vector2(x, y);
        }

        // Compound assignment (vector)
        Vector2& operator+=(const Vector2& v) {
            x += v.x;
            y += v.y;
            return *this;
        }

        Vector2& operator-=(const Vector2& v) {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        Vector2& operator*=(const Vector2& v) {
            x *= v.x;
            y *= v.y;
            return *this;
        }

        Vector2& operator/=(const Vector2& v) {
            x /= v.x;
            y /= v.y;
            return *this;
        }

        // Compound assignment (scalar)
        Vector2& operator*=(T scalar) {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        Vector2& operator/=(T scalar) {
            x /= scalar;
            y /= scalar;
            return *this;
        }

        // Comparison
        bool operator==(const Vector2& v) const {
            return x == v.x && y == v.y;
        }

        bool operator!=(const Vector2& v) const {
            return !(*this == v);
        }
    };

    // Free functions
    template <typename T>
    Vector2<T> operator*(T scalar, const Vector2<T>& v) {
        return v * scalar;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Vector2<T>& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
}

#endif //WIGI_VECTOR2_H