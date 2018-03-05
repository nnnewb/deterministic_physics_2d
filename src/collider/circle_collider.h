#ifndef WEAK_PTR_CIRCLE_COLLIDER_H
#define WEAK_PTR_CIRCLE_COLLIDER_H
#include "collider.h"
#include "shapes/circle.h"

namespace weak_ptr {
    template <typename Real>
    struct circle_collider : collider<Real> {
        circle<Real> circle_shape;

        bool collide_with(const collider<Real>& other, const transform<Real>& xf) override;
    };
}

#endif // WEAK_PTR_CIRCLE_COLLIDER_H
