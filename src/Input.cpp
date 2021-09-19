#include <Input.hpp>

using wars::Input;

Input::Input(Window& window): m_window(window)
{
    glfwSetMouseButtonCallback(m_window.m_window, mouseButtonCallback);
    glfwSetCursorPosCallback(m_window.m_window, mousePosCallback);
    
    glfwSetWindowUserPointer(m_window.m_window, this);
}




void Input::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    Input* obj = reinterpret_cast<Input*>(glfwGetWindowUserPointer(window));
    obj->m_mouseButtons[button] = action;
}





void Input::mousePosCallback(GLFWwindow* window, double xpos, double ypos)
{
    Input* obj = reinterpret_cast<Input*>(glfwGetWindowUserPointer(window));
    obj->m_mousePos.x = xpos;
    obj->m_mousePos.y = ypos;
}