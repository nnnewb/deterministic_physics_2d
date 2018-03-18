#ifndef UNIQ_COLLIDER_POLYGON_H
#define UNIQ_COLLIDER_POLYGON_H

#include <utility>
#include "collider.h"
#include "../shapes/polygon.h"

namespace uniq {
    template <typename Real>
    struct collider_polygon : collider<Real> {
        polygon<Real> polygon_shape;

        explicit collider_polygon(polygon<Real> poly)
            : collider<Real>(k_polygon)
            , polygon_shape(std::move(poly)) { }

        collider_polygon(const collider_polygon& other) = default;

        collider_polygon(collider_polygon&& other) noexcept = default;

        collider_polygon& operator=(const collider_polygon& other) = default;

        collider_polygon& operator=(collider_polygon&& other) noexcept = default;

        ~collider_polygon() override = default;

        bool collide_with(const collider<Real>& other) const override {
            switch (other.type) {
            case k_polygon:
                return collide_with(dynamic_cast<const collider_polygon&>(other));
            case k_circle:
            case k_unknow:
            default:
                ;
            }
            throw std::logic_error("This method not implemented.");
        }

        bool collide_with(const vec2<Real>& p) const override {
            if (polygon_shape.compute_aabb().collide_point(p)) {
                for (auto edge : polygon_shape) {
                    auto self_projection = polygon_shape.project(edge.norml());
                    auto p_projection = p.dot(edge.norml()) / edge.norml().length;
                    if (!math::contains(p_projection, self_projection.first, self_projection.second)) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        bool collide_with(const collider_polygon& other) const {
            for (auto edge : polygon_shape) {
                vec2<Real> axis = edge.norml();

                // project to this axis
                auto self_projection = polygon_shape.project(axis);
                auto other_projection = other.polygon_shape.project(axis);
                if (!math::overlap(self_projection.first,
                                   self_projection.second,
                                   other_projection.first,
                                   other_projection.second)) {
                    return false;
                }
            }
            return true;
        }

        vec2<Real> seprate_vec(const collider<Real>& other) const override {
            throw std::logic_error("This method not implemented.");
        }

        void translate(const transform<Real>& xf) override {
            polygon_shape.translate(xf);
        }
    };
}

#endif // UNIQ_COLLIDER_POLYGON_H
