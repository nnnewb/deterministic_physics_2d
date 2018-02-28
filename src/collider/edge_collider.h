#ifndef WEAK_PTR_EDGE_COLLIDER_H
#define WEAK_PTR_EDGE_COLLIDER_H

#include <shapes/edge.h>
#include "collider.h"

namespace weak_ptr {
    template <typename Real>
    struct edge_collider : collider<Real> {
        edge<Real> edge_shape;
    };
}

#endif // WEAK_PTR_EDGE_COLLIDER_H
