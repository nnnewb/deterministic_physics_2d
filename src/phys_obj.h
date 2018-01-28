#ifndef WEAK_PTR_PHYS_OBJ_H
#define WEAK_PTR_PHYS_OBJ_H
#include "aabb.h"
#include "phys_body.h"

namespace weak_ptr {
    class UserData {
    public:
        UserData(const UserData& other) = default;

        UserData(UserData&& other) noexcept = default;

        UserData& operator=(const UserData& other) = default;

        UserData& operator=(UserData&& other) noexcept = default;

        UserData() = default;

        virtual ~UserData() = 0;
    };

    template <typename Real>
    struct phys_obj {
        UserData* user_data;
        phys_body<Real> body;
    };
}

#endif // WEAK_PTR_PHYS_OBJ_H
