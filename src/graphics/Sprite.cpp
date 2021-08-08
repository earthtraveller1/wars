#include <graphics/Sprite.hpp>
#include <graphics/Mesh.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <graphics/Shader.hpp>

using graphics::Sprite;

Sprite::Sprite(Mesh& p_mesh): mesh(p_mesh) {
    modelMatrix = glm::mat4(1.0f);
    dir = Direction::LEFT;
}

void Sprite::draw(Shader& shader) {
    shader.setUniform("model", modelMatrix);
    mesh.render();
}

void Sprite::move(float x, float y) {
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, 0.0f));
}

void Sprite::turn(float degree) {
    modelMatrix = glm::rotate(modelMatrix, glm::radians(degree), glm::vec3(0.0, 0.0, 1.0));
}

void Sprite::setDirection(Direction pdir) {
    if (pdir == Direction::LEFT && dir == Direction::RIGHT) {
        modelMatrix = glm::rotate(modelMatrix, glm::radians(180.0f), glm::vec3(0.0, 1.0, 0.0));
        dir = Direction::LEFT;
    } else if (pdir == Direction::RIGHT && dir == Direction::LEFT) {
        modelMatrix = glm::rotate(modelMatrix, glm::radians(180.0f), glm::vec3(0.0, 1.0, 0.0));
        dir = Direction::RIGHT;
    }
}