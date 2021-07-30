#include "../Resources.hpp"
#include <graphics/Material.hpp>
#include <graphics/Shader.hpp>
#include <graphics/TextureAtlas.hpp>

using graphics::Material;
using graphics::Shader;
using graphics::TextureAtlas;

Shader* Resources::Shaders::defaultShader = nullptr;
TextureAtlas* Resources::TextureAtlases::atlas1 = nullptr;
Material* Resources::Materials::atlas1 = nullptr;

void Resources::prepareMaterials() {
    Materials::atlas1 = new Material(*Shaders::defaultShader, *TextureAtlases::atlas1);
}

void Resources::prepareShaders() {
    Shaders::defaultShader = new Shader("shaders/default.glsl");
}

void Resources::prepareTextureAtlases() {
    TextureAtlases::atlas1 = new TextureAtlas("textures/texture-atlas-1.png");
}