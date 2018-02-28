#ifndef WEAK_PTR_SHAPE_POLYGON_H
#define WEAK_PTR_SHAPE_POLYGON_H
#include "shape.h"
#include "vec2.h"
#include <vector>
#include <ostream>
#include "aabb.h"

namespace weak_ptr {
    template <typename Real>
    struct polygon : shape<Real> {
        std::vector<vec2<Real>> vertices;

        polygon();

        explicit polygon(const std::vector<vec2<Real>>& vertices);

        ~polygon() override = default;

        aabb<Real> compute_aabb() const override;

        friend std::ostream& operator<<(std::ostream& os, const polygon& obj) {
            return os
                   << static_cast<const shape<Real>&>(obj)
                   << " vertices: " << obj.vertices;
        }
    };

    template <typename Real>
    polygon<Real>::polygon() {
        this->type = shape<Real>::shape_type::k_polygon;
    }

    template <typename Real>
    polygon<Real>::polygon(const std::vector<vec2<Real>>& vertices)
        : polygon() {
        this->vertices = vertices;
    }

    template <typename Real>
    aabb<Real> polygon<Real>::compute_aabb() const {
        // todo: calculate aabb around polygon shape
        return {};
    }
}

#endif // WEAK_PTR_SHAPE_POLYGON_H