#ifndef UNIQ_RENDE_COLLIDER_H
#define UNIQ_RENDE_COLLIDER_H

#include "SDL2pp/SDL2pp.hh"
#include "../src/collider/collider_circle.h"
#include "../src/collider/collider_polygon.h"
#include "render_shapes.h"

namespace uniq {
    template <typename Real>
    void render(SDL2pp::Renderer& renderer,
                const collider_circle<Real>& render_collider,
                const SDL2pp::Color& color) {
        render(renderer, render_collider.circle_shape, color, true);
    }

    template <typename Real>
    void render(SDL2pp::Renderer& renderer,
                const collider_polygon<Real>& render_collider,
                const SDL2pp::Color& color) {
        render(renderer, render_collider.polygon_shape, color, true);
    }
}

#endif // UNIQ_RENDER_COLLIDER_H
