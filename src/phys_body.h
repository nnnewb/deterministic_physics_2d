#ifndef WEAK_PTR_PHYS_BODY_H
#define WEAK_PTR_PHYS_BODY_H

#include "aabb.h"
#include "rect.h"
#include "circle.h"

namespace weak_ptr {
    template<typename Real>
    struct phys_body {
        enum {
            k_rect,
            k_circle,
        } storage_type;

        union {
            rect<Real> rect;
            circle<Real> circle;
        };
        aabb<Real> box;
    };
}

#endif // WEAK_PTR_PHYS_BODY_H
