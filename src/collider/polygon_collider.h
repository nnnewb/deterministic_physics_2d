#ifndef WEAK_PTR_POLYGON_COLLIDER_H
#define WEAK_PTR_POLYGON_COLLIDER_H
#include "collider.h"
#include "shapes/polygon.h"

namespace weak_ptr {
    template <typename Real>
    struct polygon_collider : collider<Real> {
        polygon<Real> polygon_shape;

        bool collide_with(const collider<Real>& other, const transform<Real>& xf) override;
    };
}

#endif // WEAK_PTR_POLYGON_COLLIDER_H
