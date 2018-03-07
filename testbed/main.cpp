#include "SDL2pp/SDL2pp.hh"
#include "SDL.h"
#include "shapes/polygon.h"
#include "shapes/circle.h"

#include "render_shapes.h"
#include "render_collider.h"

int main(int argc, char* argv[]) {
    SDL2pp::SDL ctx(SDL_INIT_EVERYTHING);
    SDL2pp::Window window("TestBed", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (static_cast<SDL_EventType>(event.type)) {
            case SDL_FIRSTEVENT:
                break;
            case SDL_QUIT:
                running = false;
                break;
            case SDL_APP_TERMINATING:
                break;
            case SDL_APP_LOWMEMORY:
                break;
            case SDL_APP_WILLENTERBACKGROUND:
                break;
            case SDL_APP_DIDENTERBACKGROUND:
                break;
            case SDL_APP_WILLENTERFOREGROUND:
                break;
            case SDL_APP_DIDENTERFOREGROUND:
                break;
            case SDL_WINDOWEVENT:
                break;
            case SDL_SYSWMEVENT:
                break;
            case SDL_KEYDOWN:
                break;
            case SDL_KEYUP:
                break;
            case SDL_TEXTEDITING:
                break;
            case SDL_TEXTINPUT:
                break;
            case SDL_KEYMAPCHANGED:
                break;
            case SDL_MOUSEMOTION:
                break;
            case SDL_MOUSEBUTTONDOWN:
                break;
            case SDL_MOUSEBUTTONUP:
                break;
            case SDL_MOUSEWHEEL:
                break;
            case SDL_JOYAXISMOTION:
                break;
            case SDL_JOYBALLMOTION:
                break;
            case SDL_JOYHATMOTION:
                break;
            case SDL_JOYBUTTONDOWN:
                break;
            case SDL_JOYBUTTONUP:
                break;
            case SDL_JOYDEVICEADDED:
                break;
            case SDL_JOYDEVICEREMOVED:
                break;
            case SDL_CONTROLLERAXISMOTION:
                break;
            case SDL_CONTROLLERBUTTONDOWN:
                break;
            case SDL_CONTROLLERBUTTONUP:
                break;
            case SDL_CONTROLLERDEVICEADDED:
                break;
            case SDL_CONTROLLERDEVICEREMOVED:
                break;
            case SDL_CONTROLLERDEVICEREMAPPED:
                break;
            case SDL_FINGERDOWN:
                break;
            case SDL_FINGERUP:
                break;
            case SDL_FINGERMOTION:
                break;
            case SDL_DOLLARGESTURE:
                break;
            case SDL_DOLLARRECORD:
                break;
            case SDL_MULTIGESTURE:
                break;
            case SDL_CLIPBOARDUPDATE:
                break;
            case SDL_DROPFILE:
                break;
            case SDL_DROPTEXT:
                break;
            case SDL_DROPBEGIN:
                break;
            case SDL_DROPCOMPLETE:
                break;
            case SDL_AUDIODEVICEADDED:
                break;
            case SDL_AUDIODEVICEREMOVED:
                break;
            case SDL_RENDER_TARGETS_RESET:
                break;
            case SDL_RENDER_DEVICE_RESET:
                break;
            case SDL_USEREVENT:
                break;
            case SDL_LASTEVENT:
                break;
            }
        }

        renderer.SetDrawColor({0xff, 0xff, 0xff});
        renderer.Clear();
        uniq::polygon<double> poly{{{100, 100}, {50, 50}, {150, 50}}};
        // uniq::circle<double> circle{{250, 250}, 30};
        uniq::collider_polygon<double> poly_collider(poly);
        render(renderer, poly_collider, {0, 0, 0});
        // render(renderer, circle, {0, 0, 0}, true);
        renderer.Present();
    }
    return 0;
}
