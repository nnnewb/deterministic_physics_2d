#ifndef WEAK_PTR_COLLIDER_H
#define WEAK_PTR_COLLIDER_H

#include <utils/transform.h>

namespace weak_ptr {
    template <typename Real>
    struct collider {

        virtual bool collide_with(const collider &other, const transform &xf) =0;

        virtual ~collider() =0;
    };
}

#endif // WEAK_PTR_COLLIDER_H
