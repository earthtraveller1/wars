#include "../Resources.hpp"
#include <graphics/Shader.hpp>
#include <GLFW/glfw3.h>
#include "../Input.hpp"
#include "../Time.hpp"
#include <iostream>
#include <graphics/TextureAtlas.hpp>
#include "../Scenes.hpp"
#include "../CollisionBox.hpp"
#include "../Scene.hpp"

#include "Scene1.hpp"

Scene1::Scene1(): background(*Resources::Meshes::gameBackground) {
    player.move(-110.0f, -93.0f);
    
    zombie1.move(150.0, -93.0);
    zombie2.move(250.0, -93.0);
    zombie3.move(350.0, -93.0);
    
    zombie1.setDirection(graphics::Direction::LEFT);
    zombie2.setDirection(graphics::Direction::LEFT);
    zombie3.setDirection(graphics::Direction::LEFT);
}

void Scene1::render() {
    Resources::TextureAtlases::atlas1->bind();
    background.draw(*Resources::Shaders::defaultShader);
    
    bullet.draw(*Resources::Shaders::defaultShader);

    player.draw(*Resources::Shaders::defaultShader);
    
    zombie1.draw(*Resources::Shaders::defaultShader);
    zombie2.draw(*Resources::Shaders::defaultShader);
    zombie3.draw(*Resources::Shaders::defaultShader);
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