#ifndef WEAK_PTR_CIRCLE_H
#define WEAK_PTR_CIRCLE_H

#include "vec2.h"

#define POW2(x) ((x)*(x))

namespace weak_ptr {
    template <typename Real>
    struct circle {
        vec2<Real> center;
        Real radius;

        circle() = default;

        circle(const vec2<Real>& center, const Real& radius);

        circle(const circle& other);

        circle(circle&& other) noexcept;

        ~circle() = default;

        circle& operator=(const circle& other);

        circle& operator=(circle&& other) noexcept;

        bool has_intersection(const circle& other);
    };

    template <typename Real>
    circle<Real>::circle(const vec2<Real>& center, const Real& radius): center(center),
                                                                        radius(radius) {}

    template <typename Real>
    circle<Real>::circle(const circle& other): center(other.center),
                                               radius(other.radius) {}

    template <typename Real>
    circle<Real>::circle(circle&& other) noexcept: center(std::move(other.center)),
                                                   radius(std::move(other.radius)) {}

    template <typename Real>
    circle<Real>& circle<Real>::operator=(const circle& other) {
        if (this == &other)
            return *this;
        center = other.center;
        radius = other.radius;
        return *this;
    }

    template <typename Real>
    circle<Real>& circle<Real>::operator=(circle&& other) noexcept {
        if (this == &other)
            return *this;
        center = std::move(other.center);
        radius = std::move(other.radius);
        return *this;
    }

    template <typename Real>
    bool circle<Real>::has_intersection(const circle& other) {
        Real r = this->radius + other.radius;
        r *= r;
        return r < POW2(this->center.x + other.center.x) + POW2(this->center.y + other.center.y);
    }
}

#endif // WEAK_PTR_CIRCLE_H
