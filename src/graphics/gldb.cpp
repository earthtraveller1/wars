#include <glad/glad.h>
#include <string>
#include <iostream>

#include "gldb.hpp"

static void debug_break() {
    return;
}

void gldb::printErrors() {
    unsigned int errorCode = 0;
    while ((errorCode = glGetError()) != GL_NO_ERROR) {
        std::string error;
        switch (errorCode) {
        case GL_NO_ERROR:
            error = "GL_NO_ERROR";
            break;
        case GL_INVALID_ENUM:
            error = "GL_INVALID_ENUM";
            break;
        case GL_INVALID_VALUE:
            error = "GL_INVALID_VALUE";
            break;
        case GL_INVALID_OPERATION:
            error = "GL_INVALID_OPERATION";
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            error = "GL_INVALID_FRAMEBUFFER_OPERATION";
            break;
        case GL_OUT_OF_MEMORY:
            error = "GL_OUT_OF_MEMORY";
            break;
        case GL_STACK_UNDERFLOW:
            error = "GL_STACK_UNDERFLOW";
            break;
        case GL_STACK_OVERFLOW:
            error = "GL_STACK_OVERFLOW";
            break;
        default:
            error = "GL_UNKNOW_ERROR";
            break;
        }
        
        std::cerr << "[OPENGL ERROR]: " << error << std::endl;
        debug_break();
    }
}