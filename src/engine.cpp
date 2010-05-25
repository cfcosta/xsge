#include "engine.h"

namespace XSGE {
    Engine::Engine()
    {
        last_tick = 0;
        screen = 0;
        tick_counter = 0;
        fps_counter = 0;
        current_fps = 0;
        minimized = false;

        window = new Window(800,600);
        input = new Input();

        initialize();
    }

    Engine::~Engine()
    {
        end();
        SDL_Quit();
    }

    void Engine::run()
    {
        last_tick = SDL_GetTicks();
        
        while (true)
        {
            handle_input();
            think();
            render();
        }
    }
}
