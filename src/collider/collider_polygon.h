#ifndef UNIQ_COLLIDER_POLYGON_H
#define UNIQ_COLLIDER_POLYGON_H

#include "collider.h"
#include "../shapes/polygon.h"

namespace uniq {
    template <typename Real>
    struct collider_polygon : collider<Real> {
        polygon<Real> polygon_shape;

        explicit collider_polygon(const polygon<Real>& poly)
            : collider(k_polygon)
            , polygon_shape(poly) { }

        collider_polygon(const collider_polygon& other) = default;

        collider_polygon(collider_polygon&& other) noexcept = default;

        collider_polygon& operator=(const collider_polygon& other) = default;

        collider_polygon& operator=(collider_polygon&& other) noexcept = default;

        ~collider_polygon() override = default;

        bool collide_with(const collider<Real>& other) const override {
            throw std::logic_error("This method not implemented.");
        }

        bool collide_with(const collider_polygon& other) const {
            for (decltype(polygon_shape.compute_vertices().size()) idx = 0;
                 idx < polygon_shape.compute_vertices().size() - 1;
                 ++idx) {
                vec2<Real> edge_vec = polygon_shape.compute_vertices()[idx] - polygon_shape.compute_vertices()[idx + 1];
                vec2<Real> axis_vec = edge_vec.norml();

                // project to this axis
                auto self_projection = polygon_shape.project(axis_vec);
                auto other_projection = other.polygon_shape.project(axis_vec);
                if (!math::overlap(self_projection.first,
                                   self_projection.second,
                                   other_projection.first,
                                   other_projection.second)) {
                    return false;
                }
            }
            auto axis_vec = polygon_shape.compute_vertices().front() - polygon_shape.compute_vertices().back();
            axis_vec = axis_vec.norml();
            // project to last axis
            auto self_projection = polygon_shape.project(axis_vec);
            auto other_projection = other.polygon_shape.project(axis_vec);
            return math::overlap(self_projection.first,
                                 self_projection.second,
                                 other_projection.first,
                                 other_projection.second);
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
