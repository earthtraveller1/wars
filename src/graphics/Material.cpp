#include <graphics/Material.hpp>

graphics::Material::Material() {
    
}

graphics::Material::Material(Shader p_shader): shader(p_shader) {
    
}

void graphics::Material::use() {
    shader.use();
}