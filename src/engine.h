#ifndef XSGE_ENGINE
#define XSGE_ENGINE

#include <SDL.h>

#include "window.h"

namespace XSGE
{
    class Engine
    {
        public:
            Engine();
            virtual ~Engine();

            void run();
            int get_fps();

            void pre_render();

            Window get_window();
        private:
            long last_tick;
            int tick_counter;
            int fps_counter;
            int current_fps;

            bool quit;
            
            Window *window = new Window(800,600);
        protected:
            virtual void initialize();
            virtual void think(int elapsed_time);
            virtual void render(SDL_Surface destination_surface);
            virtual void end();

            virtual void key_up();
            virtual void key_down();
    };
}

#endif
