#ifndef WEAK_PTR_SHAPE_H
#define WEAK_PTR_SHAPE_H

#include <vector>
#include "aabb.h"

namespace uniq {
    template<typename Real>
    class shape {
    public:
        virtual aabb<Real> compute_aabb() const = 0;

        virtual const std::vector<vec2<Real>>& compute_vertices() const = 0;
    };
}

#endif // WEAK_PTR_SHAPE_H
