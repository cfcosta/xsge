#ifndef XSGE_WINDOW
#define XSGE_WINDOW

namespace XSGE {
    class Window
    {
        public:
            Window(arguments);
            virtual ~Window();

            void set_size(int width, int height);
            void set_title(const char* title);

            virtual void active();
            virtual void inactive();

            const char* get_title();
        private:
            const char* title;
            bool minimized;

            int width;
            int height;
    };
}

#endif
