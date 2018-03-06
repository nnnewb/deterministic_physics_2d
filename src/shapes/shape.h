#ifndef WEAK_PTR_SHAPE_H
#define WEAK_PTR_SHAPE_H

namespace uniq {
    template <typename Real>
    struct shape {
        virtual aabb<Real> aabb() const =0;
    };
}

#endif // WEAK_PTR_SHAPE_H
