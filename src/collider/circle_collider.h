#ifndef WEAK_PTR_CIRCLE_COLLIDER_H
#define WEAK_PTR_CIRCLE_COLLIDER_H
#include "collider.h"

namespace weak_ptr {
    template <typename Real>
    struct circle_collider : collider<Real> {
        bool collide_with(const collider<Real>& other) override;
    };

    template <typename Real>
    bool circle_collider<Real>::collide_with(const collider<Real>& other) {
        return false;
    }
}

#endif // WEAK_PTR_CIRCLE_COLLIDER_H
