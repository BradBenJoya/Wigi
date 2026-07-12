#ifndef WIGI_VECTOR2_H
#define WIGI_VECTOR2_H
#include "SFML/System/Vector2.hpp"
#include <ostream>

namespace wigi {
    template <typename T>
    struct Vector2 {
        constexpr Vector2() noexcept = default;
        constexpr Vector2(T x, T y) noexcept : x(x), y(y) {}
        constexpr Vector2(const sf::Vector2<T>& v) noexcept : x(v.x), y(v.y) {}

        T x, y;

        constexpr operator sf::Vector2<T>() const noexcept {
            return sf::Vector2<T>(x, y);
        }

        // Arithmetic (vector-vector)
        constexpr Vector2 operator+(const Vector2& v) const noexcept {
            return Vector2(x + v.x, y + v.y);
        }

        constexpr Vector2 operator-(const Vector2& v) const noexcept {
            return Vector2(x - v.x, y - v.y);
        }

        constexpr Vector2 operator*(const Vector2& v) const noexcept {
            return Vector2(x * v.x, y * v.y);
        }

        constexpr Vector2 operator/(const Vector2& v) const noexcept {
            return Vector2(x / v.x, y / v.y);
        }

        // Arithmetic (vector-scalar)
        constexpr Vector2 operator*(T scalar) const noexcept {
            return Vector2(x * scalar, y * scalar);
        }

        constexpr Vector2 operator/(T scalar) const noexcept {
            return Vector2(x / scalar, y / scalar);
        }

        // Unary
        constexpr Vector2 operator-() const noexcept {
            return Vector2(-x, -y);
        }

        constexpr Vector2 operator+() const noexcept {
            return Vector2(x, y);
        }

        // Compound assignment (vector)
        constexpr Vector2& operator+=(const Vector2& v) noexcept {
            x += v.x;
            y += v.y;
            return *this;
        }

        constexpr Vector2& operator-=(const Vector2& v) noexcept {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        constexpr Vector2& operator*=(const Vector2& v) noexcept {
            x *= v.x;
            y *= v.y;
            return *this;
        }

        constexpr Vector2& operator/=(const Vector2& v) noexcept {
            x /= v.x;
            y /= v.y;
            return *this;
        }

        // Compound assignment (scalar)
        constexpr Vector2& operator*=(T scalar) noexcept {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        constexpr Vector2& operator/=(T scalar) noexcept {
            x /= scalar;
            y /= scalar;
            return *this;
        }

        // Comparison
        constexpr bool operator==(const Vector2& v) const noexcept {
            return x == v.x && y == v.y;
        }

        constexpr bool operator!=(const Vector2& v) const noexcept {
            return !(*this == v);
        }
    };

    // Free functions
    template <typename T>
    constexpr Vector2<T> operator*(T scalar, const Vector2<T>& v) noexcept {
        return v * scalar;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Vector2<T>& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
}

#endif //WIGI_VECTOR2_H