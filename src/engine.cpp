#include "engine.h"

namespace XSGE {
    Engine::Engine()
    {
        last_tick = 0;
        tick_counter = 0;
        fps_counter = 0;
        current_fps = 0;

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
        quit = false;
        
        while (!quit)
        {
            long elapsed_ticks = SDL_GetTicks() - last_tick;
            last_tick = SDL_GetTicks();

            handle_input();
            think(elapsed_ticks);
            pre_render();

            tick_counter += elapsed_ticks;
        }
    }

    void Engine::handle_input()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        quit = true;
                        break;
                    }
                    
                    key_down(event.key.keysym.sym);
                    break;
                case SDL_KEYUP:
                    key_up(event.key.keysym.sym);
                    break;
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }
    }

    void Engine::pre_render()
    {
        ++fps_counter;

        if (tick_counter > 1000)
        {
            current_fps = fps_counter;
            fps_counter = 0;
            tick_counter = 0;
        }

        window->render(this);
    }

    int Engine::get_fps()
    {
        return this->current_fps;
    }
}
