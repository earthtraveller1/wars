#ifndef D7C55208_25B8_4746_A614_E83B687B2458
#define D7C55208_25B8_4746_A614_E83B687B2458

struct GLFWwindow;

#include <pch.hpp>

namespace wars::engine
{
    extern const uint16_t WINDOW_WIDTH = 960;
    extern const uint16_t WINDOW_HEIGHT = 540;
    
    class window
    {
    public:
        static window& get_instance();
        
        void show() const;
        
        bool is_open() const;
        
        void update() const;
        
        ~window();
        
    private:
        // constructors are made private
        window();
        window(window& src);
        window(window&& src);
        
        // The window handle
        GLFWwindow* m_window;
        
        // The keyboard callback
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };
}

#endif /* D7C55208_25B8_4746_A614_E83B687B2458 */
