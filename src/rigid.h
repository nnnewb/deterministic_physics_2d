#ifndef UNIQ_RIGID_H
#define UNIQ_RIGID_H
#include "collider/collider.h"

namespace uniq {
    template <typename Real>
    class rigid_body {
        collider<Real>* collider_;

    public:
        explicit rigid_body(collider<Real>* collider)
            : collider_(collider) {}

        rigid_body(const rigid_body& other) = delete;

        rigid_body(rigid_body&& other) noexcept = delete;

        rigid_body& operator=(const rigid_body& other) = delete;

        rigid_body& operator=(rigid_body&& other) noexcept = delete;

        ~rigid_body() = default;

        collider<Real>* getCollider() const { return collider_; }
    };
}

#endif // UNIQ_RIGID_H
