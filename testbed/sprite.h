#ifndef UNIQ_SPRITE_H
#define UNIQ_SPRITE_H

#include "../src/collider/collider.h"
#include "../src/transform.h"
#include "render_collider.h"

namespace uniq {
    template<typename Real>
    class sprite {
        collider <Real> *collider_ = nullptr;
        SDL_Color color_{0, 0, 0};

    public:
        const SDL_Color &get_color() const { return color_; }

        void set_color(const SDL_Color &color) { color_ = color; }

        void render(SDL2pp::Renderer &renderer) const {
            switch (collider_->type) {
                case k_unknow:
                    std::cerr << "Unknow collider, can not render it." << std::endl;
                    break;
                case k_polygon:
                    uniq::render(renderer, *dynamic_cast<collider_polygon<Real> *>(collider_), color_);
                    break;
                case k_circle:
                    uniq::render(renderer, *dynamic_cast<collider_circle<Real> *>(collider_), color_);
                    break;
            }
        }

        void translate(const transform <Real> &xf) {
            collider_->translate(xf);
        }

        virtual void on_mouse_press(SDL_Event ev) {}

        virtual void on_mouse_release(SDL_Event ev) {}

        virtual void on_key_press(SDL_Event ev) {}

        virtual void on_key_release(SDL_Event ev) {}

        virtual void on_mouse_enter(SDL_Event ev) {
            color_ = {0, 0xff, 0};
        }

        virtual void on_mouse_leave(SDL_Event ev) {
            color_ = {0, 0, 0};
        }
    };
}
#endif // UNIQ_SPRITE_H
