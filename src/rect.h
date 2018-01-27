#ifndef WEAK_PTR_RECT_H
#define WEAK_PTR_RECT_H

#include "vec2.h"
#include "aabb.h"
#include <utility>

namespace weak_ptr {
    template <typename Real>
    struct rect {
        vec2<Real> center;
        Real width, height;

        rect() = default;

        rect(const vec2<Real>& center, const Real& width, const Real& height);

        rect(const rect& other);

        rect(rect&& other) noexcept;

        ~rect() = default;

        rect& operator=(const rect& other);

        rect& operator=(rect&& other) noexcept;

        aabb<Real> as_aabb() noexcept;

        bool has_intersection(const rect& other) noexcept;
    };

    template <typename Real>
    rect<Real>::rect(const vec2<Real>& center, const Real& width, const Real& height): center(center),
                                                                                       width(width),
                                                                                       height(height) {}

    template <typename Real>
    rect<Real>::rect(const rect& other): center(other.center),
                                         width(other.width),
                                         height(other.height) {}

    template <typename Real>
    rect<Real>::rect(rect&& other) noexcept: center(std::move(other.center)),
                                             width(std::move(other.width)),
                                             height(std::move(other.height)) {}

    template <typename Real>
    rect<Real>& rect<Real>::operator=(const rect& other) {
        if (this == &other)
            return *this;
        center = other.center;
        width = other.width;
        height = other.height;
        return *this;
    }

    template <typename Real>
    rect<Real>& rect<Real>::operator=(rect&& other) noexcept {
        if (this == &other)
            return *this;
        center = std::move(other.center);
        width = std::move(other.width);
        height = std::move(other.height);
        return *this;
    }

    template <typename Real>
    aabb<Real> rect<Real>::as_aabb() noexcept {
        return aabb<Real>{
            {
                center.x - width / 2,
                center.y - height / 2
            },
            {
                center.x + width / 2,
                center.y + height / 2
            }
        };
    }

    template <typename Real>
    bool rect<Real>::has_intersection(const rect& other) noexcept {
        return as_aabb().has_intersection(other.as_aabb());
    }
}

#endif // WEAK_PTR_RECT_H
