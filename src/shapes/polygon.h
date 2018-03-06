#ifndef DETERMINISTIC_PHYSICS_2D_POLYGON_H
#define DETERMINISTIC_PHYSICS_2D_POLYGON_H

#include <algorithm>
#include "shape.h"

namespace uniq {
    template<typename Real>
    class polygon : public shape<Real> {
        std::vector<vec2<Real>> vertices_;
        aabb<Real> aabb_;

        static aabb<Real> make_aabb_from_vertices(const std::vector<vec2<Real>> &vertices) {
            assert(vertices.size() >= 3);
            vec2<Real> min = vertices[0], max = vertices[0];
            for (auto v : vertices) {
                if (v.x < min.x) min.x = v.x;
                if (v.x > max.x) max.x = v.x;
                if (v.y < min.y) min.y = v.y;
                if (v.y > max.y) max.y = v.y;
            }
            return uniq::aabb<Real>{min, max};
        }

    public:
        explicit polygon(const std::vector<vec2<Real>> &vertices)
            : vertices_(vertices), aabb_(make_aabb_from_vertices(vertices)) {
        }

        aabb<Real> compute_aabb() const override {
            return aabb_;
        }

        const std::vector<vec2<Real>> &compute_vertices() const override {
            return vertices_;
        }
    };
}

#endif //DETERMINISTIC_PHYSICS_2D_POLYGON_H
