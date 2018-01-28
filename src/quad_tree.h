#ifndef WEAK_PTR_QUAD_TREE_H
#define WEAK_PTR_QUAD_TREE_H

#include "quad_tree_node.h"

namespace weak_ptr {
    template <typename Real>
    struct quad_tree {
        std::shared_ptr<quad_tree_node<Real>> root;

        explicit quad_tree(const aabb<Real>& boarder, i32 node_objs_maximum = 25);
    };

    template <typename Real>
    quad_tree<Real>::quad_tree(const aabb<Real>& boarder, i32 node_objs_maximum) {
        root = std::make_shared<quad_tree_node<Real>>(boarder, node_objs_maximum);
    }
}

#endif // WEAK_PTR_QUAD_TREE_H
