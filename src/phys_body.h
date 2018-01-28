#ifndef WEAK_PTR_PHYS_BODY_H
#define WEAK_PTR_PHYS_BODY_H

#include "aabb.h"
#include "rect.h"
#include "circle.h"
#include <utility>
#include <cassert>
#include <algorithm>

namespace weak_ptr {
    template <typename Real>
    struct phys_body {
        enum {
            k_rect,
            k_circle,
        } storage_type;

        union {
            rect<Real> u_rect;
            circle<Real> u_circle;
        };

        aabb<Real> box;

        explicit phys_body(const circle<Real>& circle);

        explicit phys_body(const rect<Real>& rect);

        phys_body(const phys_body& other);

        phys_body(phys_body&& other) noexcept;

        phys_body& operator=(const phys_body& other);

        phys_body& operator=(phys_body&& other) noexcept {
            if (this == &other)
                return *this;
            storage_type = other.storage_type;
            switch (storage_type) {
            case k_rect:
                u_rect = std::move(other.u_rect);
                break;
            case k_circle:
                u_circle = std::move(other.u_circle);
                break;
            default:
                assert(false);
            }
            box = std::move(other.box);
            return *this;
        }
    };

    template <typename Real>
    phys_body<Real>::phys_body(const circle<Real>& circle)
        : storage_type(k_circle),
          u_circle(circle),
          box(circle.center - vec2<Real
              >(circle.radius, circle.radius),
              circle.center + vec2<Real
              >(circle.radius, circle.radius)) { }

    template <typename Real>
    phys_body<Real>::phys_body(const rect<Real>& rect)
        : storage_type(k_rect),
          u_rect(rect),
          box(rect.as_aabb()) {}

    template <typename Real>
    phys_body<Real>::phys_body(const phys_body& other)
        : storage_type(other.storage_type),
          box(other.box) {
        switch (storage_type) {
        case k_rect:
            u_rect = other.u_rect;
            break;
        case k_circle:
            u_circle = other.u_circle;
            break;
        default:
            assert(false);
        }
    }

    template <typename Real>
    phys_body<Real>::phys_body(phys_body&& other) noexcept
        : storage_type(other.storage_type),
          box(std::move(other.box)) {
        switch (storage_type) {
        case k_rect:
            u_rect = std::move(other.u_rect);
            break;
        case k_circle:
            u_circle = std::move(other.u_circle);
            break;
        default:
            assert(false);
        }
    }

    template <typename Real>
    phys_body<Real>& phys_body<Real>::operator=(const phys_body& other) {
        if (this == &other)
            return *this;
        storage_type = other.storage_type;
        switch (storage_type) {
        case k_rect:
            u_rect = other.u_rect;
            break;
        case k_circle:
            u_circle = other.u_circle;
            break;
        default:
            assert(false);
        }
        box = other.box;
        return *this;
    }
}

#endif // WEAK_PTR_PHYS_BODY_H
