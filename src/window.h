#ifndef XSGE_WINDOW
#define XSGE_WINDOW

namespace XSGE {
    class Window
    {
        public:
            Window(int width, int height, const char* title = "Unnamed Window");
            virtual ~Window();

            void set_size(int width, int height);
            void set_title(const char* title);

            const char* get_title();
            SDL_Surface* get_screen();

            virtual void active();
            virtual void inactive();
        private:
            const char* title;

            int width;
            int height;

            SDL_Surface *screen;
    };
}

#endif
