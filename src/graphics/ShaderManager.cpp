#include <glad/glad.h>
#include "gldb.hpp"

#include "ShaderManager.hpp"

using graphics::ShaderManager;

ShaderManager& ShaderManager::getInstance() {
    static ShaderManager instance;
    return instance;
}

unsigned int ShaderManager::add(unsigned int shader) {
    shaders.push_back(shader);
}

void ShaderManager::remove(unsigned int index) {
    shaders.at(index) = 0;
}

ShaderManager::~ShaderManager() {
    for (auto i = shaders.begin(); i != shaders.end(); i++) {
        if (*i != 0) glCall(glDeleteProgram, *i);
    }
}