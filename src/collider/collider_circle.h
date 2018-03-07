#ifndef UNIQ_COLLIDER_CIRCLE_H
#define UNIQ_COLLIDER_CIRCLE_H

#include "collider.h"
#include "../shapes/circle.h"

namespace uniq {
    template <typename Real>
    struct collider_circle : collider<Real> {
        circle<Real> circle_shape;

        explicit collider_circle(const circle<Real>& circ)
            : circle_shape(circ) {}

        collider_circle(const collider_circle& other) = default;

        collider_circle(collider_circle&& other) noexcept = default;

        collider_circle& operator=(const collider_circle& other) = default;

        collider_circle& operator=(collider_circle&& other) noexcept = default;

        ~collider_circle() override = default;

        bool collide_with(const collider<Real>& other) override {
            throw std::logic_error("This method not implemented.");
        }

        vec2<Real> seprate_vec(const collider<Real>& other) override {
            throw std::logic_error("This method not implemented.");
        }
    };
}

#endif // UNIQ_COLLIDER_CIRCLE_H