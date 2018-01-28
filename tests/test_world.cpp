#include "aabb.h"
#include "vec2.h"
#include "quad_tree.h"
#include <gtest/gtest.h>

TEST(WorldTest, QuadTreeNodeInsertion) {
    weak_ptr::quad_tree_node<weak_ptr::f64> root{
        weak_ptr::aabb<weak_ptr::f64>({-25.0, -25.0}, {25.0, 25.0}),
        25
    };

    root.insert(
        new weak_ptr::phys_obj<weak_ptr::f64>(
            weak_ptr::phys_body<weak_ptr::f64>(
                weak_ptr::circle<weak_ptr::f64>(
                    weak_ptr::vec2<weak_ptr::f64>(0.5, 0.5),
                    0.5))));
}
