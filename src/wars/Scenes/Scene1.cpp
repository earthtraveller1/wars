#include "../Resources.hpp"
#include <graphics/Mesh.hpp>
#include <graphics/Sprite.hpp>
#include <graphics/Shader.hpp>
#include <GLFW/glfw3.h>
#include "../Input.hpp"
#include "../Time.hpp"
#include <iostream>
#include <graphics/TextureAtlas.hpp>
#include "../Scenes.hpp"

#include "Scene1.hpp"

Scene1::Scene1(): player(*Resources::Meshes::player), background(*Resources::Meshes::gameBackground) {
    player.move(-110.0f, -93.0f);
}

void Scene1::render() {
    Resources::TextureAtlases::atlas1->bind();
    background.draw(*Resources::Shaders::defaultShader);
    player.draw(*Resources::Shaders::defaultShader);
}

void Scene1::update(double deltaTime) {
    if (Input::isKeyDown(GLFW_KEY_W)) {
        player.setDirection(graphics::Direction::RIGHT);
        player.move(100 * deltaTime, 0);
    }
    if (Input::isKeyDown(GLFW_KEY_S)) {
        player.setDirection(graphics::Direction::LEFT);
        player.move(100 * deltaTime, 0);
    }
    
    if (Input::isKeyDown(GLFW_KEY_ESCAPE)) {
        Scene::setActive(reinterpret_cast<Scene*>(Scenes::scene0));
    }
}