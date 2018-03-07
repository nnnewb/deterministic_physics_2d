#ifndef UNIQ_TRANSFORM_H
#define UNIQ_TRANSFORM_H
#include "vec2.h"

namespace uniq {
    template<typename Real>
    struct transform {
        vec2<Real> motion;
        Real rotation;
    };
}

#endif // UNIQ_TRANSFORM_H
