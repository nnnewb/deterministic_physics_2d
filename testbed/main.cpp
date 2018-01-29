#include "world.h"
#include "SDL2pp/SDL.hh"
#include <SDL.h>
#include "SDL2pp/Window.hh"
#include "SDL2pp/Renderer.hh"
#include "render.h"

using namespace weak_ptr;

int main(int argc, char* argv[]) {
    quad_tree_node<double> root{{{0, 0}, {800, 600}}, 25};
    std::vector<phys_obj<double>> objs;
    objs.assign(50, phys_obj<double>{phys_body<double>{rect<double>{{400, 300}, 50, 50}}});
    for (auto obj : objs) {
        root.insert(&obj);
    }
    SDL2pp::SDL sdl(SDL_INIT_EVERYTHING);
    SDL2pp::Window window("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    window.Show();
    SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event ev;
    while (true) {
        while (SDL_PollEvent(&ev)) {
            const auto type = static_cast<SDL_EventType>(ev.type);
            switch (type) {
            case SDL_FIRSTEVENT: break;
            case SDL_QUIT: goto end;
            case SDL_APP_TERMINATING: break;
            case SDL_APP_LOWMEMORY: break;
            case SDL_APP_WILLENTERBACKGROUND: break;
            case SDL_APP_DIDENTERBACKGROUND: break;
            case SDL_APP_WILLENTERFOREGROUND: break;
            case SDL_APP_DIDENTERFOREGROUND: break;
            case SDL_WINDOWEVENT: break;
            case SDL_SYSWMEVENT: break;
            case SDL_KEYDOWN: break;
            case SDL_KEYUP: break;
            case SDL_TEXTEDITING: break;
            case SDL_TEXTINPUT: break;
            case SDL_KEYMAPCHANGED: break;
            case SDL_MOUSEMOTION: break;
            case SDL_MOUSEBUTTONDOWN: break;
            case SDL_MOUSEBUTTONUP: break;
            case SDL_MOUSEWHEEL: break;
            case SDL_JOYAXISMOTION: break;
            case SDL_JOYBALLMOTION: break;
            case SDL_JOYHATMOTION: break;
            case SDL_JOYBUTTONDOWN: break;
            case SDL_JOYBUTTONUP: break;
            case SDL_JOYDEVICEADDED: break;
            case SDL_JOYDEVICEREMOVED: break;
            case SDL_CONTROLLERAXISMOTION: break;
            case SDL_CONTROLLERBUTTONDOWN: break;
            case SDL_CONTROLLERBUTTONUP: break;
            case SDL_CONTROLLERDEVICEADDED: break;
            case SDL_CONTROLLERDEVICEREMOVED: break;
            case SDL_CONTROLLERDEVICEREMAPPED: break;
            case SDL_FINGERDOWN: break;
            case SDL_FINGERUP: break;
            case SDL_FINGERMOTION: break;
            case SDL_DOLLARGESTURE: break;
            case SDL_DOLLARRECORD: break;
            case SDL_MULTIGESTURE: break;
            case SDL_CLIPBOARDUPDATE: break;
            case SDL_DROPFILE: break;
            case SDL_DROPTEXT: break;
            case SDL_DROPBEGIN: break;
            case SDL_DROPCOMPLETE: break;
            case SDL_AUDIODEVICEADDED: break;
            case SDL_AUDIODEVICEREMOVED: break;
            case SDL_RENDER_TARGETS_RESET: break;
            case SDL_RENDER_DEVICE_RESET: break;
            case SDL_USEREVENT: break;
            case SDL_LASTEVENT: break;
            default: ;
            }
        }
        renderer.Clear();
        render(renderer, root);
        renderer.Present();
        SDL_Delay(1000 / 60);
    }
end:
    return 0;
}
