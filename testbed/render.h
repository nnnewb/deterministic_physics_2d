#ifndef WEAK_PTR_RENDER_H
#define WEAK_PTR_RENDER_H

#include "SDL2pp/Renderer.hh"
#include "quad_tree_node.h"
#include "SDL2pp/Color.hh"
#include "phys_obj.h"

namespace weak_ptr {
    template <typename Real>
    void render(SDL2pp::Renderer& renderer, const aabb<Real>& box, SDL2pp::Color color) {
        const auto backup = renderer.GetDrawColor();
        renderer.SetDrawColor(color);
        renderer.DrawRect(box.min.x, box.min.y, box.max.x, box.max.y);
        renderer.SetDrawColor(backup);
    }

    template <typename Real>
    void render(SDL2pp::Renderer& renderer, const phys_obj<Real>& obj) {
        render(renderer, obj.body.box, SDL2pp::Color{0xff, 0, 0});
    }

    template <typename Real>
    void render(SDL2pp::Renderer& renderer, const quad_tree_node<Real>& node) {
        render(renderer, node.boarder_box, SDL2pp::Color{0x23, 0x23, 0x23});
        for (const phys_obj<Real>* obj : node.objs) {
            render(renderer, *obj);
        }
        for (const auto& n : node.nodes) {
            if (nullptr != n) render(renderer, *n);
        }
    }
}

#endif // WEAK_PTR_RENDER_H
