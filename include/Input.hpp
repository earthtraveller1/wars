#ifndef A79BF4B2_6C27_4F38_BB54_FC50DE1EEE3E
#define A79BF4B2_6C27_4F38_BB54_FC50DE1EEE3E

#include <pch.hpp>
#include <array>

#include <Window.hpp>

namespace wars
{
    struct MousePos
    {
        uint32_t x;
        uint32_t y;
    };
    
    
    
    
    
    class Input
    {
    public:
        explicit Input(Window& window);
        
        bool isKeyDown(int32_t key);
        
        bool isKeyUp(int32_t key);
        
        bool isMouseButtonDown(int32_t button);
        
        uint32_t getMouseX();
        
        uint32_t getMouseY();
        
        MousePos getMousePos();
        
    private:
        // The window object
        Window& m_window;
        
        // The position of the cursor.
        MousePos m_mousePos;
        
        // The state of all the mouse buttons
        std::array<bool, GLFW_MOUSE_BUTTON_LAST> mouseButtons;
        
        // The mouse button callback
        void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        
        // The cursor position callback
        void mousePosCallback(GLFWwindow* window, double xpos, double ypos);
    };
}

#endif /* A79BF4B2_6C27_4F38_BB54_FC50DE1EEE3E */
