#include <graphics/Shader.hpp>

#include <string>
#include <fstream>
#include <iostream>

#include <glad/glad.h>

#include <utils/file-utils.hpp>

#include <graphics/ShaderManager.hpp>
#include <graphics/gldb.hpp>

using graphics::Shader;

static bool startsWith(std::string_view a, std::string_view b) {
    if (b.size() > a.size()) {
        return false;
    }
    
    for (std::string_view::iterator i = a.begin(), j = b.begin(); j != b.end(); i++, j++) {
        if (*j != *i) {
            return false;
        }
    }
    
    return true;
}

namespace { struct ShaderSources {
    std::string vertex;
    std::string fragment;
};}

static ShaderSources processShader(std::string_view path) {
    ShaderSources result;
    
    std::ifstream file(path.data());
    if (!file) {
        std::cerr << "[ERROR]: Could not find or open " << path << std::endl;
        return { "", "" };
    }
    
    enum class ShaderMode {
        NONE, VERTEX, FRAGMENT
    } mode = ShaderMode::NONE;
    
    while(!file.eof()) {
        std::string line;
        std::getline(file, line);
        
        if (startsWith(line, "//@")) {
            if (startsWith(line, "//@ vertex")) {
                mode = ShaderMode::VERTEX;
            } else if (startsWith(line, "//@ fragment")) {
                mode = ShaderMode::FRAGMENT;
            }
        } else {
            if (mode == ShaderMode::VERTEX) {
                result.vertex += line += "\n";
            } else if (mode == ShaderMode::FRAGMENT) {
                result.fragment += line += "\n";
            }
        }
    }
    
    return result;
}

static unsigned int createShader(std::string_view p_source, unsigned int type = GL_VERTEX_SHADER, std::string_view name = "Shader") {
    const char* source = p_source.data();
    
    unsigned int shader;
    shader = glCallR(glCreateShader, type);
    glCall(glShaderSource, shader, 1, &source, nullptr);
    glCall(glCompileShader, shader);
    
    int success;
    glCall(glGetShaderiv, shader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        int errorLogLength;
        glCall(glGetShaderiv, shader, GL_INFO_LOG_LENGTH, &errorLogLength);
        char* errorLog = new char[errorLogLength];
        glCall(glGetShaderInfoLog, shader, errorLogLength, &errorLogLength, errorLog);
        
        std::cerr << "[ERROR]: Failed to compile " << name << ":\n" << errorLog << "\n\n";
        
        delete[] errorLog;
    }
    
    return shader;
}

static unsigned int createProgram(unsigned int vertex, unsigned int fragment, std::string_view name = "Shader Program") {
    unsigned int program;
    program = glCallRN(glCreateProgram);
    glCall(glAttachShader, program, vertex);
    glCall(glAttachShader, program, fragment);
    glCall(glLinkProgram, program);
    
    int success;
    glCall(glGetProgramiv, program, GL_LINK_STATUS, &success);
    if (success == GL_FALSE) {
        int errorLogLength;
        glCall(glGetProgramiv, program, GL_INFO_LOG_LENGTH, &errorLogLength);
        char* errorLog = new char[errorLogLength];
        glCall(glGetProgramInfoLog, program, errorLogLength, &errorLogLength, errorLog);
        
        std::cerr << "[ERROR]: Failed to link " << name << ":\n" << errorLog << "\n\n";
        
        delete[] errorLog;
    }
    
    return program;
}

Shader::Shader(): Shader("shaders/default.glsl") {
    
}

Shader::Shader(std::string_view path) {
    ShaderSources shaderSources = processShader(path);
    unsigned int vertex = createShader(shaderSources.vertex, GL_VERTEX_SHADER, std::string(path) + std::string("/vertex"));
    unsigned int fragment = createShader(shaderSources.fragment, GL_FRAGMENT_SHADER, std::string(path) + std::string("/fragment"));
    
    program = createProgram(vertex, fragment, path);
    
    // Delete the shaders, we don't need them anymore since that they are linked to the program
    glCall(glDeleteShader, vertex);
    glCall(glDeleteShader, fragment);
    
    graphics::ShaderManager& shaderManager = graphics::ShaderManager::getInstance();
    index = shaderManager.add(program);
}

Shader::Shader(std::string_view vertexPath, std::string_view fragmentPath, std::string_view name) {
    std::string vertexSource = fileutils::loadAsString(vertexPath);
    std::string fragmentSource = fileutils::loadAsString(fragmentPath);
    
    unsigned int vertex = createShader(vertexSource, GL_VERTEX_SHADER, vertexPath);
    unsigned int fragment = createShader(fragmentSource, GL_FRAGMENT_SHADER, fragmentPath);
    
    program = createProgram(vertex, fragment, name);
    
    // Delete the shaders, we don't need them anymore since that they are linked to the program
    glCall(glDeleteShader, vertex);
    glCall(glDeleteShader, fragment);
    
    graphics::ShaderManager& shaderManager = graphics::ShaderManager::getInstance();
    index = shaderManager.add(program);
}

void Shader::use() {
    glCall(glUseProgram, program);
}

void Shader::setUniform(std::string_view name, int value) {
    glCall(glUniform1i, glCallR(glGetUniformLocation, program, name.data()), value);
}

void Shader::destroy() {
    graphics::ShaderManager& shaderManager = graphics::ShaderManager::getInstance();
    shaderManager.remove(index);
    
    glCall(glDeleteProgram, program);
}