#ifndef XSGE_ENGINE
#define XSGE_ENGINE

#include <SDL.h>

#include "window.h"
#include "input.h"

namespace XSGE
{
    class Engine
    {
        public:
            Engine();
            virtual ~Engine();

            void run();

            virtual void initialize();
            virtual void think(int time_elapsed);
            virtual void render(SDL_Surface destination_surface);
            virtual void end();

            int get_fps();

            Window get_window();
            Input get_input();
        private:
            long last_tick;
            int tick_counter;
            int fps_counter;
            int current_fps;
            
            Window window;
            Input input;
        protected:
            void think();
            void render();
            void handle_input();
    };
}

#endif
