#include <pch.hpp>
#include <GameOptions.hpp>
#include <Window.hpp>

#include <stdexcept>

using wars::Window;

void* getOpenGLFunctionProcAddress(const char* name) {
    return reinterpret_cast<void*>(glfwGetProcAddress(name));
}




static void glDebugOutput(
    GLenum p_source, GLenum p_type, unsigned int p_id, GLenum p_severity, GLsizei p_length, const char* p_message, 
    const void* p_userParam
)
{
    std::string source;
    switch (p_source)
    {
        case GL_DEBUG_SOURCE_API:
            source = "API";
            break;
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
            source = "WINDOW SYSTEM";
            break;
        case GL_DEBUG_SOURCE_SHADER_COMPILER:
            source = "SHADER COMPILER";
            break;
        case GL_DEBUG_SOURCE_THIRD_PARTY:
            source = "THIRD PARTY";
            break;
        case GL_DEBUG_SOURCE_APPLICATION:
            source = "APPLICATION";
            break;
        case GL_DEBUG_SOURCE_OTHER:
            source = "OTHER";
            break;
    }
    
    std::string type;
    switch (p_type)
    {
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
            type = "DEPRECATED BEHAVIOUR";
            break;
        case GL_DEBUG_TYPE_ERROR:
            type = "ERROR";
            break;
        case GL_DEBUG_TYPE_MARKER:
            type = "MARKER";
            break;
        case GL_DEBUG_TYPE_OTHER:
            type = "OTHER";
            break;
        case GL_DEBUG_TYPE_PERFORMANCE:
            type = "PERFORMANCE";
            break;
        case GL_DEBUG_TYPE_POP_GROUP:
            type = "POP GROUP";
            break;
        case GL_DEBUG_TYPE_PORTABILITY:
            type = "UNDEFINED BEHAVIOUR";
            break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
            type = "PORTABILITY";
            break;
        case GL_DEBUG_TYPE_PUSH_GROUP:
            type = "PORTABILITY";
            break;
    }
    
    std::string severity;
    switch (p_severity)
    {
        case GL_DEBUG_SEVERITY_HIGH:
            severity = "HIGH";
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            severity = "HIGH";
            break;
        case GL_DEBUG_SEVERITY_LOW:
            severity = "HIGH";
            break;
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            severity = "HIGH";
            break;
    }
    
    std::cout << "[OPENGL " << source << " " << type << " "
              << p_id << "]: " << p_message << std::endl;
    return;
}




Window::Window() 
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW.");
    }
    
    if (GameOptions::enableOpenGLContextDebugging)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
    } else
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    m_window = glfwCreateWindow(960, 540, "@#Wars", nullptr, nullptr);
    if (m_window == nullptr) 
    {
        throw std::runtime_error("Failed to create the main window.");
    }
    
    glfwMakeContextCurrent(m_window);
    
    if (!gladLoadGLLoader(getOpenGLFunctionProcAddress)) {
        throw std::runtime_error("Failed to load OpenGL.");
    }
    
    if (GameOptions::enableOpenGLContextDebugging)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(glDebugOutput, nullptr);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, 
                              GL_DONT_CARE, 0, nullptr, true);
    }
}




void Window::update() {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}