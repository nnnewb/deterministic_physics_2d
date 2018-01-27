#ifndef WEAK_PTR_AABB_H
#define WEAK_PTR_AABB_H

#include "vec2.h"
#include <ostream>

namespace weak_ptr {

    // aabb - axis-aligned-boarder-box
    template <typename Real>
    struct aabb {
        vec2<Real> min;
        vec2<Real> max;

        aabb() = default;

        aabb(const vec2<Real>& min, const vec2<Real>& max);

        aabb(const aabb& other);

        aabb(aabb&& other) noexcept;

        aabb& operator=(const aabb& other);

        aabb& operator=(aabb&& other) noexcept;

        ~aabb() = default;

        friend bool operator==(const aabb& lhs, const aabb& rhs) {
            return lhs.min == rhs.min
                && lhs.max == rhs.max;
        }

        friend bool operator!=(const aabb& lhs, const aabb& rhs) {
            return !(lhs == rhs);
        }

        friend std::ostream& operator<<(std::ostream& os, const aabb& obj) {
            return os
                << "min: " << obj.min
                << " max: " << obj.max;
        }

        bool has_intersection(const aabb& other);
    };

    // aabb implementation

    template <typename Real>
    aabb<Real>::aabb(const vec2<Real>& min, const vec2<Real>& max): min(min),
                                                                    max(max) {}

    template <typename Real>
    aabb<Real>::aabb(const aabb& other): min(other.min),
                                         max(other.max) {}

    template <typename Real>
    aabb<Real>::aabb(aabb&& other) noexcept: min(std::move(other.min)),
                                             max(std::move(other.max)) {}

    template <typename Real>
    aabb<Real>& aabb<Real>::operator=(const aabb& other) {
        if (this == &other)
            return *this;
        min = other.min;
        max = other.max;
        return *this;
    }

    template <typename Real>
    aabb<Real>& aabb<Real>::operator=(aabb&& other) noexcept {
        if (this == &other)
            return *this;
        min = std::move(other.min);
        max = std::move(other.max);
        return *this;
    }

    template <typename Real>
    bool aabb<Real>::has_intersection(const aabb& other) {
        // Exit with no intersection if found separated along an axis
        if (this->max.x < other.min.x || this->min.x > other.max.x) return false;
        if (this->max.y < other.min.y || this->min.y > other.max.y) return false;
        // No separating axis found, therefor there is at least one overlapping axis
        return true;
    }
}

#endif // WEAK_PTR_AABB_H
