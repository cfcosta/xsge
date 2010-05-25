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
            void handle_input();

            Window get_window();

        private:
            long last_tick;
            int tick_counter;
            int fps_counter;
            int current_fps;

            bool quit;
            
            Window *window;

        protected:
            virtual void initialize();
            virtual void think(int elapsed_time);
            virtual void render(SDL_Surface render);
            virtual void end();

            virtual void key_up(SDLKey &key);
            virtual void key_down(SDLKey &key);
    };
}
