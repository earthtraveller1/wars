#include <vector>
#include <glad/glad.h>
#include <graphics/gldb.hpp>

#include <graphics/TextureAtlasManager.hpp>

using graphics::TextureAtlasManager;

TextureAtlasManager::TextureAtlasManager() {
    
}

TextureAtlasManager& TextureAtlasManager::getInstance() {
    static TextureAtlasManager textureAtlasManager;
    return textureAtlasManager;
}

unsigned int TextureAtlasManager::add(unsigned int atlas) {
    atlases.push_back(atlas);
    return latestIndex++;
}

void TextureAtlasManager::remove(unsigned int index) {
    atlases[index] = 0;
}

TextureAtlasManager::~TextureAtlasManager() {
    for (auto it = atlases.begin(); it != atlases.end(); it++) {
        if (*it != 0) {
            glCall(glDeleteTextures, 1, &(*it));
        }
    }
}