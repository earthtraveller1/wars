#include "Window.hpp"

#include "Input.hpp"

// The target window
static GLFWwindow* window = nullptr;

bool Input::isKeyDown(int key) {
    return (glfwGetKey(window, key) == GLFW_PRESS);
}

void Input::setWindow(Window& window) {
    ::window = window.window;
}