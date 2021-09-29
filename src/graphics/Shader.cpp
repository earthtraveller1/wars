#include <pch.hpp>
#include <graphics/Shader.hpp>
#include <sstream>

using wars::graphics::Shader;

namespace
{
    struct ShaderSources
    {
        std::string vertex;
        std::string fragment;
    };
}

static unsigned int createShader(const char* source, unsigned int type, std::string_view name = "shader")
{
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    
    int success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE)
    {
        int errorLogLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorLogLength);
        char* errorLog = new char[errorLogLength];
        glGetShaderInfoLog(shader, errorLogLength, &errorLogLength, errorLog);
        
        std::cerr << "[ERROR]: Failed to compile " << name << ":\n";
        std::cerr << errorLog << "\n\n";
        
        delete[] errorLog;
    }
    
    return shader;
}




static ShaderSources splitShaderSource(std::string_view source)
{
    std::stringstream sourceStream(source.data());
    
    ShaderSources result = {};
    
    enum class ShaderType
    {
        NONE = 0, VERTEX, FRAGMENT
    };
    
    ShaderType type = ShaderType::NONE;
    
    std::string line;
    
    bool looping = true;
    while (looping)
    {
        std::getline(sourceStream, line);
        
        if (line == "//@@## vertex")
        {
            type = ShaderType::VERTEX;
        } else if (line == "//@@## fragment")
        {
            type = ShaderType::FRAGMENT;
        } else {
            switch (type)
            {
                case ShaderType::VERTEX:
                    result.vertex += line += "\n";
                    break;
                case ShaderType::FRAGMENT:
                    result.fragment += line += "\n";
                    break;
            }
        }
    }
    
    return result;
}




Shader::Shader(std::string_view source)
{
    ShaderSources sources = splitShaderSource(source);
    
    unsigned int vertex = createShader(sources.vertex.c_str(), GL_VERTEX_SHADER, "a vertex shader");
    unsigned int fragment = createShader(sources.fragment.c_str(), GL_FRAGMENT_SHADER, "a fragment shader");
    
    m_shader = glCreateProgram();
    glAttachShader(m_shader, vertex);
    glAttachShader(m_shader, fragment);
    glLinkProgram(m_shader);
    
    int success = 0;
    glGetProgramiv(m_shader, GL_LINK_STATUS, &success);
    if (success == GL_FALSE)
    {
        int errorLogLength = 0;
        glGetProgramiv(m_shader, GL_INFO_LOG_LENGTH, &errorLogLength);
        char* errorLog = new char[errorLogLength];
        glGetProgramInfoLog(m_shader, errorLogLength, &errorLogLength, errorLog);
        
        std::cout << "[ERROR]: Failed to link a shader program:\n" << errorLog << "\n\n";
    }
}