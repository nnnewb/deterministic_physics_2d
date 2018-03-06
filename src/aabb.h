#ifndef UNIQ_AABB_H
#define UNIQ_AABB_H

#include "vec2.h"

namespace uniq {
    template<typename Real>
    struct aabb {
        vec2<Real> min, max;

        aabb(vec2<Real> min, vec2<Real> max)
            : min(min),
              max(max) {
        }
    };
}

#endif // UNIQ_AABB_H
