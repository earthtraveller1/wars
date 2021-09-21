#ifndef CF41F68A_E27E_45DF_8DB7_7B8CC823EAEF
#define CF41F68A_E27E_45DF_8DB7_7B8CC823EAEF

#include <GLFW/glfw3.h>

namespace wars
{
    // This class is fairly straightforward. It is simply a wrapper around
    // GLFW's windowing system. That's because it has only one purpose: create
    // a window and keep the rest of the game running until the user closes
    // that window.
    class Window
    {
    public:
        // Make the input class a friend so that it can obtain the GLFW window
        // handle.
        friend class Input;
        
        // Create a 960x540 window titled "@#Wars".
        Window();
        
        // The window will be invisible upon creation. Call this method to show
        // it.
        void show() { glfwShowWindow(m_window); }
        
        // Tells you if the window is still open.
        bool isOpen() { return !glfwWindowShouldClose(m_window); }
        
        // Swap front and back buffers and polls GLFW events
        void update();
        
        // Destroys the window. Doesn't terminate GLFW though.
        ~Window() { glfwDestroyWindow(m_window); }
        
    private:
        // The handle to the actual handle
        GLFWwindow* m_window;
    };
}

#endif /* CF41F68A_E27E_45DF_8DB7_7B8CC823EAEF */
