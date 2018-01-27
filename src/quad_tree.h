#ifndef WEAK_PTR_QUAD_TREE_H
#define WEAK_PTR_QUAD_TREE_H
#include <array>
#include "phys_obj.h"
#include <vector>

namespace weak_ptr {
    template <typename Real>
    struct quad_tree_node {
        std::vector<phys_obj<Real>*> objs;
        std::array<quad_tree_node*, 4> nodes;
    };
}

#endif // WEAK_PTR_QUAD_TREE_H
