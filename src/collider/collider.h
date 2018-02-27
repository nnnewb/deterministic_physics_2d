#ifndef WEAK_PTR_COLLIDER_H
#define WEAK_PTR_COLLIDER_H

namespace weak_ptr {
    template <typename Real>
    struct collider {

        virtual bool collision_test_with(const collider& other) =0;

        virtual ~collider() =0;
    };
}

#endif // WEAK_PTR_COLLIDER_H
