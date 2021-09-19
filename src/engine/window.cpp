#include <engine/window.hpp>

#include <GLFW/glfw3.h>
#include <stdexcept>
#include <engine/events/event_queues.hpp>

using namespace wars::engine;

const uint16_t wars::engine::WINDOW_WIDTH = 960;
const uint16_t wars::engine::WINDOW_HEIGHT = 540;


window& window::get_instance()
{
    static window win;
    return win;
}




window::window() 
{
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW.");
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    m_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "@#Wars", nullptr, nullptr);
    
    if (m_window == nullptr) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window.");
    }
    
    glfwMakeContextCurrent(m_window);
    
    const GLFWvidmode* video_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(m_window, (video_mode->width - WINDOW_WIDTH) / 2, (video_mode->height - WINDOW_HEIGHT) / 2);
    
    glfwSetKeyCallback(m_window, key_callback);
}





void window::show() const 
{
    glfwShowWindow(m_window);
}




void window::update() const
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}




window::~window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}




void window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        events::key_press_event event(key);
        events::queues::key_press_queue.push_back(event);
    }
}