#include <glad/glad.h>
#include <graphics/gldb.hpp>
#include <stb_image.h>

#include <graphics/TextureAtlas.hpp>

using graphics::TextureAtlas;

void TextureAtlas::moveFrom(TextureAtlas& src) {
    texture = src.texture;
    
    src.texture = 0;
}

void TextureAtlas::destroy() {
    glCall(glDeleteTextures, 1, &texture);
}

TextureAtlas::TextureAtlas(): TextureAtlas("texture-atlas.png") {
    
}

TextureAtlas::TextureAtlas(std::string_view imagePath) {
    stbi_set_flip_vertically_on_load(true);
    
    int width, height, nrChannels;
    unsigned char* data = stbi_load(imagePath.data(), &width, &height, &nrChannels, 0);
    
    unsigned int format;
    switch(nrChannels) {
    case 1:
        format = GL_RED;
        break;
    case 2:
        format = GL_RG;
        break;
    case 3:
        format = GL_RGB;
        break;
    case 4:
        format = GL_RGBA;
        break;
    default:
        format = GL_RGBA;
        break;
    }
    
    glCall(glGenTextures, 1, &texture);
    glCall(glBindTexture, GL_TEXTURE_2D, texture);
    
    glCall(glTexImage2D, GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glCall(glGenerateMipmap, GL_TEXTURE_2D);
    
    glCall(glBindTexture, GL_TEXTURE_2D, 0);
}

TextureAtlas::TextureAtlas(TextureAtlas& src) {
    glCall(glBindTexture, GL_TEXTURE_2D, src.texture);
    
    int width, height, internalFormat;
    glCall(glGetTexLevelParameteriv, GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
    glCall(glGetTexLevelParameteriv, GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
    glCall(glGetTexLevelParameteriv, GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &internalFormat);
    
    glCall(glBindTexture, GL_TEXTURE_2D, 0);
    
    glCall(glGenTextures, 1, &texture);
    glCall(glBindTexture, GL_TEXTURE_2D, texture);
    
    glCall(glTexImage2D, GL_TEXTURE_2D, 0, internalFormat, width, height, 0, internalFormat, GL_UNSIGNED_BYTE, nullptr);
    glCall(glCopyImageSubData, src.texture, GL_TEXTURE_2D, 0, 0, 0, 0, texture, GL_TEXTURE_2D, 0, 0, 0, 0, width, height, 0);
    
    glCall(glBindTexture, GL_TEXTURE_2D, 0);
}

TextureAtlas& TextureAtlas::operator=(TextureAtlas& rhs) {
    TextureAtlas copy(rhs);
    std::swap(*this, copy);
    return *this;
}

TextureAtlas::TextureAtlas(TextureAtlas&& src) {
    moveFrom(src);
}

TextureAtlas& TextureAtlas::operator=(TextureAtlas&& rhs) {
    destroy();
    moveFrom(rhs);
    return *this;
}

void TextureAtlas::bind() {
    glCall(glBindTexture, GL_TEXTURE_2D, texture);
}

void TextureAtlas::unbind() {
    glCall(glBindTexture, GL_TEXTURE_2D, 0);
}

TextureAtlas::~TextureAtlas() {
    destroy();
}