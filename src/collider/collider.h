#ifndef UNIQ_COLLIDER_H
#define UNIQ_COLLIDER_H

#include "../vec2.h"
#include "collider_enum.h"

namespace uniq {
    template <typename Real>
    struct collider {
        collider_type type = k_unknow;

        explicit collider(const collider_type t)
            : type(t) {};

        collider(const collider& other) = default;

        collider(collider&& other) noexcept = default;

        collider& operator=(const collider& other) = default;

        collider& operator=(collider&& other) noexcept = default;

        virtual ~collider() = default;

        virtual bool collide_with(const collider& other) const = 0;

        virtual bool collide_with(const vec2<Real>& p) const = 0;

        virtual vec2<Real> seprate_vec(const collider& other) const = 0;

        virtual void translate(const transform<Real>& xf) = 0;

    };
}

#endif // UNIQ_COLLIDER_H
