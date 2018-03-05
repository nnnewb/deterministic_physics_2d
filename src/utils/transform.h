#ifndef WEAK_PTR_TRANSFORM_H
#define WEAK_PTR_TRANSFORM_H
#include "vec2.h"
#include <ostream>
#include <cmath>

namespace weak_ptr {

    // phys object transform infomation, for collision detection and shapes separation
    template <typename Real>
    struct transform {
        vec2<Real> velocity;
        Real rotation;

        void set_velocity(vec2<Real> v);

        void set_rotation(Real rotation);

        void clear();

        friend std::ostream& operator<<(std::ostream& os, const transform& obj) {
            return os
                   << "velocity: " << obj.velocity
                   << " rotation: " << obj.rotation;
        }
    };

    template <typename Real>
    void transform<Real>::set_velocity(vec2<Real> v) {
        this->velocity = v;
    }

    template <typename Real>
    void transform<Real>::set_rotation(Real rotation) {
        this->rotation = rotation;
    }

    template <typename Real>
    void transform<Real>::clear() {
        velocity = {0, 0};
        rotation = NAN;
    }
}

#endif // WEAK_PTR_TRANSFORM_H
