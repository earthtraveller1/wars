#include "../Resources.hpp"
#include <graphics/TextureAtlas.hpp>
#include <glad/glad.h>
#include <graphics/gldb.hpp>

#include "Scene0.hpp"

Scene0::Scene0(): background(*Resources::Meshes::scene0Background) {
    
}

void Scene0::render() {
    Resources::TextureAtlases::atlas0->bind();
    background.draw(*Resources::Shaders::defaultShader);
}

void Scene0::update(double deltaTime) {
    
}