#ifndef DETERMINISTIC_PHYSICS_2D_EVENTLOOP_H
#define DETERMINISTIC_PHYSICS_2D_EVENTLOOP_H

#include "SDL2pp/SDL2pp.hh"
#include <vector>
#include "sprite.h"

namespace uniq {
    template<typename Real>
    class mainloop {
        SDL2pp::SDL context_;
        SDL2pp::Renderer renderer_;

        bool quit_ = false;
        SDL_Event event_;
        std::vector<sprite<Real>> pool_;

        void mouse_event() const {
            switch ((SDL_EventType) event_.type) {
                case SDL_MOUSEMOTION:
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    break;
                case SDL_MOUSEBUTTONUP:
                    break;
                case SDL_MOUSEWHEEL:
                    break;
                default:
                    break;
            }
        }

        void keyboard_event() const {
            switch ((SDL_EventType) event_.type) {
                case SDL_KEYDOWN:
                    break;
                case SDL_KEYUP:
                    break;
                case SDL_KEYMAPCHANGED:
                    break;
                default:
                    break;
            }
        }

        void system_event() {
            switch ((SDL_EventType) event_.type) {
                case SDL_QUIT:
                    quit_ = true;
                    break;
                case SDL_APP_WILLENTERBACKGROUND:
                    break;
                case SDL_APP_WILLENTERFOREGROUND:
                    break;
                case SDL_APP_DIDENTERBACKGROUND:
                    break;
                case SDL_APP_DIDENTERFOREGROUND:
                    break;
                default:
                    break;
            }
        }

    public:
        void run() {
            quit_ = false;
            while (!quit_) {
                while (SDL_PollEvent(&event_)) {
                    system_event();
                    mouse_event();
                    keyboard_event();
                }

                for(const sprite<Real>& sp: pool_) {
                    sp.render(renderer_);
                }

                SDL_Delay(1000 / 60);
            }
        }
    };
}

#endif //DETERMINISTIC_PHYSICS_2D_EVENTLOOP_H
