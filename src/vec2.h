#ifndef WEAK_PTR_VEC2_H
#define WEAK_PTR_VEC2_H
#include <utility>
#include <ostream>

namespace weak_ptr {
    template <typename Real>
    struct vec2 {
        Real x, y;

        vec2() = default;

        vec2(const Real& x, const Real& y);

        vec2(const vec2& other);

        vec2(vec2&& other) noexcept;

        ~vec2() = default;

        vec2& operator=(const vec2& other);

        vec2& operator=(vec2&& other) noexcept;

        constexpr vec2 operator+(const vec2& rhs) const noexcept {
            return {x + rhs.x, y + rhs.y};
        }

        constexpr vec2 operator-(const vec2& rhs) const noexcept {
            return {x - rhs.x, y - rhs.y};
        }

        constexpr vec2 operator*(const vec2& rhs) const noexcept {
            return {x * rhs.x, y * rhs.y};
        }

        constexpr vec2 operator/(const vec2& rhs) const noexcept {
            return {x / rhs.x, y / rhs.y};
        }

        friend bool operator==(const vec2& lhs, const vec2& rhs) {
            return lhs.x == rhs.x
                && lhs.y == rhs.y;
        }

        friend bool operator!=(const vec2& lhs, const vec2& rhs) {
            return !(lhs == rhs);
        }

        friend std::ostream& operator<<(std::ostream& os, const vec2& obj) {
            return os
                << "vec2 { "
                << "x: " << obj.x
                << " y: " << obj.y
                << " }";
        }

        friend std::size_t hash_value(const vec2& obj) {
            std::size_t seed = 0x028562E6;
            seed ^= (seed << 6) + (seed >> 2) + 0x459972A3 + hash_value(obj.x);
            seed ^= (seed << 6) + (seed >> 2) + 0x250B1161 + hash_value(obj.y);
            return seed;
        }
    };

    // vec2 implementation

    template <typename Real>
    vec2<Real>::vec2(const Real& x, const Real& y): x(x),
                                                    y(y) {}

    template <typename Real>
    vec2<Real>::vec2(const vec2& other): x(other.x),
                                         y(other.y) {}

    template <typename Real>
    vec2<Real>::vec2(vec2&& other) noexcept: x(std::move(other.x)),
                                             y(std::move(other.y)) {}

    template <typename Real>
    vec2<Real>& vec2<Real>::operator=(const vec2& other) {
        if (this == &other)
            return *this;
        x = other.x;
        y = other.y;
        return *this;
    }

    template <typename Real>
    vec2<Real>& vec2<Real>::operator=(vec2&& other) noexcept {
        if (this == &other)
            return *this;
        x = std::move(other.x);
        y = std::move(other.y);
        return *this;
    }
}

#endif // WEAK_PTR_VEC2_H
