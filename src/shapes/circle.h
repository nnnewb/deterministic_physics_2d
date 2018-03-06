#ifndef DETERMINISTIC_PHYSICS_2D_CIRCLE_H
#define DETERMINISTIC_PHYSICS_2D_CIRCLE_H

#include <vector>
#include "shape.h"

namespace uniq {
    template<typename Real>
    class circle : public shape<Real> {
        vec2 <Real> center_;
        Real radius_;
        aabb <Real> aabb_;
        std::vector<vec2<Real>> vertices_;

    public:
        circle(vec2 <Real> circle_center, Real circle_radius)
            : center_(circle_center),
              radius_(circle_radius),
              aabb_(center_ - vec2<Real>(radius_, radius_), center_ + vec2<Real>(radius_, radius_)) {
            vertices_.emplace_back(center_);
        }

        vec2 <Real> center() const {
            return center_;
        }

        Real radius() const {
            return radius_;
        }

        aabb <Real> compute_aabb() const override {
            return aabb_;
        }

        const std::vector<vec2<Real>> & compute_vertices() const override {
            return vertices_;
        }
    };
}

#endif //DETERMINISTIC_PHYSICS_2D_CIRCLE_H
