#include <Window.hpp>

#include <stdexcept>

using wars::Window;

Window::Window() 
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW.");
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    m_window = glfwCreateWindow(960, 540, "@#Wars", nullptr, nullptr);
    if (m_window == nullptr) 
    {
        throw std::runtime_error("Failed to create the main window.");
    }
    
    glfwMakeContextCurrent(m_window);
}




void Window::update() {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}