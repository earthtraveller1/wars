#include "../Resources.hpp"
#include <graphics/Shader.hpp>
#include <graphics/TextureAtlas.hpp>

using graphics::Shader;
using graphics::TextureAtlas;

Shader* Resources::Shaders::defaultShader = nullptr;
TextureAtlas* Resources::TextureAtlases::atlas1 = nullptr;

void Resources::prepareShaders() {
    Shaders::defaultShader = new Shader("shaders/default.glsl");
}

void Resources::prepareTextureAtlases() {
    TextureAtlases::atlas1 = new TextureAtlas("textures/texture-atlas-1.png");
}