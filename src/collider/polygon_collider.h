#ifndef WEAK_PTR_POLYGON_COLLIDER_H
#define WEAK_PTR_POLYGON_COLLIDER_H

#include "circle_collider.h"
#include "edge_collider.h"
#include "collider.h"

#include "shapes/polygon.h"

namespace weak_ptr {
    template <typename Real>
    struct polygon_collider : collider<Real> {
        polygon<Real> polygon_shape;

        bool collide_with(const collider<Real>& other) override;

        bool collide_with(const polygon_collider& other);

        bool collide_with(const edge_collider<Real>& other);

        bool collide_with(const circle_collider<Real>& other);
    };

    template <typename Real>
    bool polygon_collider<Real>::collide_with(const collider<Real>& other) {
        return false;
    }

    template <typename Real>
    bool polygon_collider<Real>::collide_with(const polygon_collider& other) {
        return false;
    }

    template <typename Real>
    bool polygon_collider<Real>::collide_with(const edge_collider<Real>& other) {
        return false;
    }

    template <typename Real>
    bool polygon_collider<Real>::collide_with(const circle_collider<Real>& other) {
        return false;
    }
}

#endif // WEAK_PTR_POLYGON_COLLIDER_H
