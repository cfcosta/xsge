#ifndef XSGE_ENGINE
#define XSGE_ENGINE

#include <SDL.h>

namespace XSGE
{
    class Engine
    {
        public:
            Engine();
            virtual ~Engine();

            void initialize();

            virtual void custom_init();
            virtual void think(int time_elapsed);
            virtual void render(SDL_Surface destination_surface);
            virtual void end();

            SDL_Surface* get_surface();
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
