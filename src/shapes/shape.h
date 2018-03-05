#ifndef WEAK_PTR_SHAPE_H
#define WEAK_PTR_SHAPE_H
#include "aabb.h"
#include "utils/sat.h"

namespace weak_ptr {
    template <typename Real>
    struct shape {
        enum class shape_type {
            k_circle = 1,
            k_edge = 2,
            k_polygon = 3,
        };

        shape_type type;

        virtual ~shape() =0;

        virtual aabb<Real> compute_aabb() const =0;

        virtual projection<Real> project(vec2<Real> axis) const = 0;
    };
}

#endif // WEAK_PTR_SHAPE_H
