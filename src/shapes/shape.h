#ifndef UNIQ_SHAPE_H
#define UNIQ_SHAPE_H

#include <vector>
#include "aabb.h"
#include "vec2.h"
#include "transform.h"

namespace uniq {
    template <typename Real>
    class shape {
    public:
        shape() = default;

        shape(const shape& other) = default;

        shape(shape&& other) noexcept = default;

        shape& operator=(const shape& other) = default;

        shape& operator=(shape&& other) noexcept = default;

        virtual ~shape() = default;

        virtual aabb<Real> compute_aabb() const = 0;

        virtual const std::vector<vec2<Real>>& compute_vertices() const = 0;

        virtual std::pair<Real, Real> project(vec2<Real> axis) const = 0;

        virtual void translate(const transform<Real>& xf) = 0;

    };
}

#endif // UNIQ_SHAPE_H
