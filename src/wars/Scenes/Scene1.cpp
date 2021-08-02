#include "../Resources.hpp"
#include <graphics/Mesh.hpp>
#include <graphics/Sprite.hpp>
#include <graphics/Shader.hpp>
#include <GLFW/glfw3.h>
#include "../Input.hpp"
#include "../Time.hpp"
#include <iostream>

#include "Scene1.hpp"

Scene1::Scene1(): player(*Resources::Meshes::player) {
    
}

void Scene1::render() {
    player.draw(*Resources::Shaders::defaultShader);
}

void Scene1::update(double deltaTime) {
    if (Input::isKeyDown(GLFW_KEY_W)) {
        player.move(100 * deltaTime, 0);
    }
    if (Input::isKeyDown(GLFW_KEY_S)) {
        player.move(-100 * deltaTime, 0);
    }
}