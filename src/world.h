#ifndef WORLD_H
#define WORLD_H
#include "quad_tree.h"

namespace weak_ptr {
    template<typename Real>
    struct phys_obj_builder;

    template <typename Real>
    class World {
        quad_tree<Real> quad_tree_;
    };

    template<typename Real>
    struct phys_obj_builder {
        World<Real>* world;

        phys_obj<Real> build(circle<Real> shape);
        phys_obj<Real> build(rect<Real> shape);
    };
}

#endif // WORLD_H
