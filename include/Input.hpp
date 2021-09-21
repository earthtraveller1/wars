#ifndef A79BF4B2_6C27_4F38_BB54_FC50DE1EEE3E
#define A79BF4B2_6C27_4F38_BB54_FC50DE1EEE3E

#include <pch.hpp>
#include <array>

#include <Window.hpp>

namespace wars
{
    // A struct which represents mouse position.
    struct MousePos
    {
        double x;
        double y;
    };
    
    
    
    
    
    // This class is meant to abstract Input handling away from the Window. It 
    // is currently state driven, meaning that it works by setting states 
    // within it's member fields and having other components query those 
    // states to check for input.
    class Input
    {
    public:
        explicit Input(Window& window);
        
        bool isKeyDown(int32_t key) { return glfwGetKey(m_window.m_window, key) == GLFW_PRESS; }
        
        bool isKeyUp(int32_t key) { return glfwGetKey(m_window.m_window, key) == GLFW_RELEASE; }
        
        bool isMouseButtonDown(int32_t button) { return m_mouseButtons[button]; }
        
        double getMouseX() { return m_mousePos.x; }
        
        double getMouseY() { return m_mousePos.y; }
        
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
