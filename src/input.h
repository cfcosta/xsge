#ifndef XSGE_INPUT
#define XSGE_INPUT

namespace XSGE
{
    class Input {
        public:
            Input();
            virtual ~Input();

            virtual void key_down(int keycode);
            virtual void key_up(int keycode);
        private:
    };
}

#endif
