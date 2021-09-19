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
        
        bool isKeyDown(int32_t key) { return glfwGetKey(m_window.m_window, key) == GLFW_PRESS; }
        
        bool isKeyUp(int32_t key) { return glfwGetKey(m_window.m_window, key) == GLFW_RELEASE; }
        
        bool isMouseButtonDown(int32_t button) { return m_mouseButtons[button]; }
        
        uint32_t getMouseX() { return m_mousePos.x; }
        
        uint32_t getMouseY() { return m_mousePos.y; }
        
        MousePos getMousePos() { return m_mousePos; }
        
    private:
        // The window object
        Window& m_window;
        
        // The position of the cursor.
        MousePos m_mousePos;
        
        // The state of all the mouse buttons
        std::array<bool, GLFW_MOUSE_BUTTON_LAST> m_mouseButtons;
        
        // The mouse button callback
        static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        
        // The cursor position callback
        static void mousePosCallback(GLFWwindow* window, double xpos, double ypos);
    };
}

#endif /* A79BF4B2_6C27_4F38_BB54_FC50DE1EEE3E */
