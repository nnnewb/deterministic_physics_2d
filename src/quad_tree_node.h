#ifndef WEAK_PTR_QUAD_TREE_NODE_H
#define WEAK_PTR_QUAD_TREE_NODE_H
#include <memory>
#include <vector>
#include "aabb.h"
#include "type_alias.h"
#include "phys_obj.h"

namespace weak_ptr {
    // 不持有 phys_obj 的所有权，所有的 phys_obj 都归属于 world 管辖，由 world 提供 builder 构建

    template <typename Real>
    struct quad_tree_node {
        std::weak_ptr<quad_tree_node> parent;
        std::vector<phys_obj<Real>*> objs;
        std::array<std::shared_ptr<quad_tree_node>, 4> nodes;
        aabb<Real> boarder_box;
        bool is_leaf;
        const i32 objs_maximum;

        quad_tree_node(const aabb<Real>& boarder_box, const i32 objs_maximum);

        void insert(phys_obj<Real>* obj);

        void split();
    };

    template <typename Real>
    quad_tree_node<Real>::quad_tree_node(const aabb<Real>& boarder_box, const i32 objs_maximum):
        boarder_box(boarder_box),
        is_leaf(true),
        objs_maximum(objs_maximum) {}

    template <typename Real>
    void quad_tree_node<Real>::insert(phys_obj<Real>* obj) {
        if (is_leaf) {
            objs.push_back(obj);
            if (objs.size() == objs_maximum) {
                split();
            }
        }
        else {
            quad_tree_node* result = nullptr;
            for (quad_tree_node* node : nodes) {
                if (obj->body.box.has_intersection(node->boarder_box)) {
                    if (nullptr == result) {
                        result = node;
                    }
                    else {
                        // cross multiple zone
                        objs.push_back(obj);
                        return;
                    }
                }
            }
            result->insert(obj);
        }
    }

    template <typename Real>
    void quad_tree_node<Real>::split() {
        std::fill_n(nodes.begin(), nodes.size(), nullptr);
        auto w = boarder_box.max.x - boarder_box.min.x, h = boarder_box.max.y - boarder_box.min.y;
        aabb<Real> lt{
            boarder_box.min,
            boarder_box.max + vec2<Real>(w / 2, h / 2)

        }, rt{
            boarder_box.min + vec2<Real>(w / 2, 0),
            boarder_box.max - vec2<Real>(0, h / 2)
        }, lb{
            boarder_box.min + vec2<Real>(0, h / 2),
            boarder_box.max - vec2<Real>(w / 2, 0)
        }, rb{
            boarder_box.min + vec2<Real>(w / 2, h / 2),
            boarder_box.max
        };

        nodes = {
            new quad_tree_node{lt, objs_maximum},
            new quad_tree_node{rt, objs_maximum},
            new quad_tree_node{lb, objs_maximum},
            new quad_tree_node{rb, objs_maximum}
        };

        is_leaf = false;

        std::vector<phys_obj<Real>> objs_copy;
        std::swap(objs_copy, objs);

        // re-insert object into quad_tree_node
        for (phys_obj<Real> obj : objs_copy) {
            insert(obj);
        }
    }
}

#endif // WEAK_PTR_QUAD_TREE_NODE_H
