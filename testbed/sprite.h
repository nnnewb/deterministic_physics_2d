#ifndef UNIQ_SPRITE_H
#define UNIQ_SPRITE_H
#include "../src/collider/collider.h"
#include "SDL2pp/Renderer.hh"
#include "render_collider.h"
#include "../src/transform.h"

namespace uniq {
    template <typename Real>
    class sprite {
        collider<Real>* collider_;
        SDL_Color color_;

    public:

        const SDL_Color& getColor() const { return color_; }

        void setColor(const SDL_Color& color) { color_ = color; }

        void render(SDL2pp::Renderer& renderer) {
            uniq::render<Real>(renderer, collider_, color_);
        }

        void translate(const transform<Real>& xf) {
            collider_->translate(xf);
        }
    };
}
#endif // UNIQ_SPRITE_H
