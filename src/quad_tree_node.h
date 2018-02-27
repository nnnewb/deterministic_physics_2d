#ifndef WEAK_PTR_QUAD_TREE_NODE_H
#define WEAK_PTR_QUAD_TREE_NODE_H
#include <array>
#include <memory>
#include <vector>
#include "aabb.h"
#include "type_alias.h"
#include "phys_obj.h"

namespace weak_ptr {

    // ������ phys_obj ������Ȩ�����е� phys_obj �������� world ��Ͻ���� world �ṩ builder ����
    template <typename Real>
    struct quad_tree_node {
        quad_tree_node* parent;
        std::vector<phys_obj<Real>*> objs;
        std::array<std::shared_ptr<quad_tree_node>, 4> nodes;
        aabb<Real> boarder_box;
        bool is_leaf;
        const i32 objs_maximum;
        uint32_t depth;
        uint32_t depth_maximum;

        quad_tree_node(quad_tree_node* parent, const aabb<Real>& boarder_box, const i32 objs_maximum, uint32_t depth,
                       uint32_t depth_max);

        void insert(phys_obj<Real>* obj);

        void split();
    };

    template <typename Real>
    quad_tree_node<Real>::quad_tree_node(quad_tree_node* parent, const aabb<Real>& boarder_box, const i32 objs_maximum,
                                         uint32_t depth,
                                         uint32_t depth_max)
        : parent(parent)
        , boarder_box(boarder_box)
        , is_leaf(true)
        , objs_maximum(objs_maximum)
        , depth(depth)
        , depth_maximum(depth_max) {}

    template <typename Real>
    void quad_tree_node<Real>::insert(phys_obj<Real>* obj) {
        if (is_leaf || depth >= depth_maximum) {
            objs.push_back(obj);
            if (objs.size() >= objs_maximum && depth < depth_maximum) {
                split();
            }
        } else {
            std::shared_ptr<quad_tree_node> result = nullptr;
            for (auto node : nodes) {
                if (obj->body.box.has_intersection(node->boarder_box)) {
                    if (nullptr == result) {
                        result = node;
                    } else {
                        // cross multiple zone
                        objs.push_back(obj);
                        return;
                    }
                }
            }
            // physics object may be out side of quadtree zone
            if (nullptr != result) {
                result->insert(obj);
            } else {
                objs.push_back(obj);
            }
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

        nodes[0] = std::make_shared<quad_tree_node>(this, lt, objs_maximum, depth + 1, depth_maximum);
        nodes[1] = std::make_shared<quad_tree_node>(this, rt, objs_maximum, depth + 1, depth_maximum);
        nodes[2] = std::make_shared<quad_tree_node>(this, lb, objs_maximum, depth + 1, depth_maximum);
        nodes[3] = std::make_shared<quad_tree_node>(this, rt, objs_maximum, depth + 1, depth_maximum);

        is_leaf = false;

        std::vector<phys_obj<Real>*> objs_copy;
        std::swap(objs_copy, objs);

        // re-insert object into quad_tree_node
        for (auto obj : objs_copy) {
            insert(obj);
        }
    }
}

#endif // WEAK_PTR_QUAD_TREE_NODE_H
