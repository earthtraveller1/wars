#include <graphics/Sprite.hpp>
#include <graphics/Material.hpp>
#include <graphics/Mesh.hpp>
#include <glm/gtc/matrix_transform.hpp>

using graphics::Sprite;

Sprite::Sprite(Mesh& p_mesh, Material& p_material): mesh(p_mesh), material(p_material) {
    
}

void Sprite::draw() {
    material.use();
    material.setUniform("model", modelMatrix);
    mesh.render();
}

void Sprite::move(int x, int y) {
    modelMatrix = glm::translate(modelMatrix, glm::vec3(static_cast<float>(x), static_cast<float>(y), 0.0f));
}

void Sprite::turn(float degree) {
    modelMatrix = glm::rotate(modelMatrix, glm::radians(degree), glm::vec3(0.0, 0.0, 1.0));
}