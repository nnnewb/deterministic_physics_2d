#ifndef UNIQ_AABB_H
#define UNIQ_AABB_H

#include "vec2.h"

namespace uniq {
    template <typename Real>
    struct aabb {
        vec2<Real> min, max;

        aabb(vec2<Real> min, vec2<Real> max)
            : min(min)
            , max(max) { }

        bool collide_point(vec2<Real> p) {
            return math::contains(p.x, min.x, max.x) && math::contains(p.y, min.y, max.y);
        }
    };
}

#endif // UNIQ_AABB_H
