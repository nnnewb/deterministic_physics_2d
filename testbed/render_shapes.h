#ifndef UNIQ_RENDER_SHAPES_H
#define UNIQ_RENDER_SHAPES_H
#include "SDL2pp/Renderer.hh"
#include "SDL2_gfxPrimitives.h"
#include "../src/shapes/polygon.h"
#include "../src/shapes/circle.h"

namespace uniq {
    template <typename Real>
    void render(SDL2pp::Renderer& renderer,
                const polygon<Real>& poly,
                const SDL2pp::Color& color,
                const bool render_aabb = false) {
        renderer.SetDrawColor(color);
        const auto& vertices = poly.compute_vertices();
        for (decltype(vertices.size()) idx = 0;
             idx < vertices.size() - 1;
             ++idx) {
            renderer.DrawLine({
                static_cast<int>(vertices[idx].x),
                static_cast<int>(vertices[idx].y)
            }, {
                static_cast<int>(vertices[idx + 1].x),
                static_cast<int>(vertices[idx + 1].y)
            });
        }
        renderer.DrawLine({
            static_cast<int>(vertices.back().x),
            static_cast<int>(vertices.back().y)
        }, {
            static_cast<int>(vertices.front().x),
            static_cast<int>(vertices.front().y)
        });

        if (render_aabb) {
            renderer.SetDrawColor({0xff, 0, 0});
            auto box = poly.compute_aabb();
            renderer.DrawRect({
                static_cast<int>(box.min.x),
                static_cast<int>(box.min.y)
            }, {
                static_cast<int>(box.max.x),
                static_cast<int>(box.max.y)
            });
        }
    }

    template <typename Real>
    void render(SDL2pp::Renderer& renderer,
                const circle<Real>& circle,
                const SDL2pp::Color& color,
                const bool render_aabb = false) {
        renderer.SetDrawColor(color);
        circleRGBA(renderer.Get(),
                   circle.center().x,
                   circle.center().y,
                   circle.radius(),
                   color.r,
                   color.g,
                   color.b,
                   color.a);
        if (render_aabb) {
            auto box = circle.compute_aabb();
            renderer.SetDrawColor({0xff, 0, 0});
            renderer.DrawRect({
                static_cast<int>(box.min.x),
                static_cast<int>(box.min.y)
            }, {
                static_cast<int>(box.max.x),
                static_cast<int>(box.max.y)
            });
        }
    }
}

#endif // UNIQ_RENDER_SHAPES_H
