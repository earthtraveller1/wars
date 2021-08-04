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

int Input::getMouseX() {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    
    return xpos;
}

int Input::getMouseY() {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    
    return ypos;
}

glm::vec2 Input::getMousePos() {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    
    return { xpos, ypos };
}

bool Input::isMouseButtonDown(int button) {
    return (glfwGetMouseButton(window, button) == GLFW_PRESS);
}

bool Input::isMouseButtonReleased(int button) {
    return (glfwGetMouseButton(window, button) == GLFW_RELEASE);
}