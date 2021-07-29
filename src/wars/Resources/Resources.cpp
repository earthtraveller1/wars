#include "../Resources.hpp"
#include <graphics/Material.hpp>
#include <graphics/Shader.hpp>
#include <graphics/TextureAtlas.hpp>

using graphics::Material;
using graphics::Shader;
using graphics::TextureAtlas;

void Resources::prepareMaterials() {
    Materials::test = new Material(*Shaders::defaultShader, *TextureAtlases::test);
}

void Resources::prepareShaders() {
    Shaders::defaultShader = new Shader("shaders/test.glsl");
}

void Resources::prepareTextureAtlases() {
    TextureAtlases::test = new TextureAtlas("textures/test.png");
}