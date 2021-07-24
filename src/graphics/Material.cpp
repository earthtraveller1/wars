#include <graphics/Material.hpp>

graphics::Material::Material(Shader& p_shader, TextureAtlas& p_atlas): shader(p_shader), textureAtlas(p_atlas) {
    
}

void graphics::Material::use() {
    shader.use();
    shader.setUniform("textureAtlas", 0);
    textureAtlas.bind();
}