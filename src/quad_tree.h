#ifndef WEAK_PTR_QUAD_TREE_H
#define WEAK_PTR_QUAD_TREE_H

#include "quad_tree_node.h"

namespace weak_ptr {
    template <typename Real>
    struct quad_tree {
        std::shared_ptr<quad_tree_node<Real>> root;

        explicit quad_tree(const aabb<Real>& boarder, i32 node_objs_maximum = 25, u32 depth_maximum = 5);

        u32 get_depth();
    };

    template <typename Real>
    quad_tree<Real>::quad_tree(const aabb<Real>& boarder, i32 node_objs_maximum, u32 depth_maximum) {
        root = std::make_shared<quad_tree_node<Real>>(nullptr, boarder, node_objs_maximum, 1, depth_maximum);
    }

    template <typename Real>
    u32 quad_tree<Real>::get_depth() {
        auto calculate_depth = [&calculate_depth](const quad_tree_node<Real>* node)-> u32 {
            if (nullptr != node) {
                auto depth = node->depth;
                for (const auto& n : node->nodes) {
                    auto child_depth = calculate_depth(n.get());
                    if (child_depth > depth) {
                        depth = child_depth;
                    }
                }
                return depth;
            } else {
                return 1;
            }
        };
        return calculate_depth(this);
    }
}

#endif // WEAK_PTR_QUAD_TREE_H
