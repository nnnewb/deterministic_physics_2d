#ifndef WEAK_PTR_SHAPE_EDGE_H
#define WEAK_PTR_SHAPE_EDGE_H
#include "shape.h"
#include "aabb.h"

namespace weak_ptr {
    template <typename Real>
    struct edge : shape<Real> {
        vec2<Real> vertex1{0, 0}, vertex2{0, 0};

        edge();

        edge(const vec2<Real>& vertex1, const vec2<Real>& vertex2);

        ~edge() override = default;

        aabb<Real> compute_aabb() const override;
    };

    template <typename Real>
    edge<Real>::edge() {
        this->type = shape<Real>::shape_type::k_edge;
    }

    template <typename Real>
    edge<Real>::edge(const vec2<Real>& vertex1, const vec2<Real>& vertex2)
        : vertex1(vertex1)
        , vertex2(vertex2) { }

    template <typename Real>
    aabb<Real> edge<Real>::compute_aabb() const {
        return {};
    }
}

#endif // WEAK_PTR_SHAPE_EDGE_H
