#ifndef UNIQ_COLLIDER_H
#define UNIQ_COLLIDER_H

#include "../vec2.h"
#include "collider_enum.h"

namespace uniq {
    template <typename Real>
    struct collider {
        collider_type type = k_unknow;

        collider() = default;

        collider(const collider& other) = default;

        collider(collider&& other) noexcept = default;

        collider& operator=(const collider& other) = default;

        collider& operator=(collider&& other) noexcept = default;

        virtual ~collider() = default;

        virtual bool collide_with(const collider& other) const = 0;

        virtual vec2<Real> seprate_vec(const collider& other) const = 0;
    };
}

#endif // UNIQ_COLLIDER_H
