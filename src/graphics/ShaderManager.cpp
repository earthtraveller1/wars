#include <glad/glad.h>
#include <graphics/gldb.hpp>

#include <graphics/ShaderManager.hpp>

using graphics::ShaderManager;

static bool firstShader = true;

ShaderManager& ShaderManager::getInstance() {
    static ShaderManager instance;
    return instance;
}

unsigned int ShaderManager::add(unsigned int shader) {
    shaders.push_back(shader);
    if (!firstShader) {
        latestIndex++;
        firstShader = false;
    }
    
    return latestIndex;
}

void ShaderManager::remove(unsigned int index) {
    shaders.at(index) = 0;
}

ShaderManager::~ShaderManager() {
    for (auto i = shaders.begin(); i != shaders.end(); i++) {
        if (*i != 0) glCall(glDeleteProgram, *i);
    }
}