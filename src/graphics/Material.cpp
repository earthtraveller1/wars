#include <graphics/Material.hpp>
#include <graphics/ProjectionMatrix.hpp>

graphics::Material::Material(Shader& p_shader, TextureAtlas& p_atlas): shader(p_shader), textureAtlas(p_atlas) {
    shader.use();
    shader.setUniform("projection", projectionMatrix);
}

void graphics::Material::use() {
    shader.use();
    shader.setUniform("textureAtlas", 0);
    textureAtlas.bind();
}