#include <stdexcept>
#include <glad/glad.h>
#include <graphics/gldb.hpp>

#include "Window.hpp"

static void initGLFW() {
    if (!glfwInit()) {
        throw std::runtime_error("[FATAL ERROR]: Failed to initialize GLFW.");
    }
}

static void setWindowHints() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

void Window::create(bool fullscreen, std::string_view title) {
    GLFWmonitor* monitor = nullptr;
    
    if (fullscreen) {
        monitor = glfwGetPrimaryMonitor();
    }
    
    window = glfwCreateWindow(width, height, title.data(), monitor, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        throw std::runtime_error("[FATAL ERROR]: Failed to create GLFW window.");
    }
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("[FATAL ERROR]: Failed to load OpenGL.");
    }
    
    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(window, (videoMode->width - width) / 2, (videoMode->height - height) / 2);
}

Window::Window(): Window(0.5, "GLFW Window", false) {
    
}

Window::Window(unsigned int width, unsigned int height, std::string_view title, bool fullscreen) {
    initGLFW();
    setWindowHints();
    
    this->width = width;
    this->height = height;
    
    create(fullscreen, title);
}

Window::Window(double multiplier, std::string_view title, bool fullscreen) {
    initGLFW();
    setWindowHints();
    
    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    
    this->width = videoMode->width * multiplier;
    this->height = videoMode->height * multiplier;
    
    create(fullscreen, title);
}

void Window::show() {
    glfwShowWindow(window);
}

bool Window::isOpen() {
    return !glfwWindowShouldClose(window);
}

void Window::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

unsigned int Window::getWidth() {
    return width;
}

unsigned int Window::getHeight() {
    return height;
}

Window::~Window() {
    glfwDestroyWindow(window);
}