#include "window.h"

namespace XSGE {
    Window::Window(int width, int height, const char *title = "Unnamed Window")
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        { fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError()); exit(1);
        }

        set_size(width, height);

        if (this->screen == NULL)
        {
            fprintf(stderr, "Unable to set up video: %s\n", SDL_GetError());
        }

        set_title(title);
    }

    void Window::set_size(int width, int height)
    {
        this->width = width;
        this->height = height;

        screen = SDL_SetVideoMode(width, height, 0, SDL_SWSURFACE);
    }

    void Window::set_title(const char *title)
    {
        this->title = title;
        SDL_WM_SetCaption(title, 0);
    }

    SDL_Surface* Window::get_screen() 
    {
        return screen;
    }
}
