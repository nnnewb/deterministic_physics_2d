#ifndef UNIQ_RIGID_H
#define UNIQ_RIGID_H
#include "collider/collider.h"

namespace uniq {
    template <typename Real>
    class rigid_body {
        collider<Real>* collider_;
    };
}


#endif // UNIQ_RIGID_H
