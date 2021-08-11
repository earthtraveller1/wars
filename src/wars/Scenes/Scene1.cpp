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
#include "../CollisionBox.hpp"

#include "Scene1.hpp"

Scene1::Scene1(): 
    player(*Resources::Meshes::player),
    zombie1(*Resources::Meshes::zombie),
    playerCBox(91.5, -91.5, 64.0, -64.0),
    zombie1CBox(36.0, -36.0, 65.5, -65.5),
    background(*Resources::Meshes::gameBackground)
{
    player.move(-110.0f, -93.0f);
    playerCBox.move(-110.0, -93.0);
    zombie1.move(200.0, -93.0);
    zombie1CBox.move(200.0, -93.0);
}

void Scene1::render() {
    Resources::TextureAtlases::atlas1->bind();
    background.draw(*Resources::Shaders::defaultShader);
    player.draw(*Resources::Shaders::defaultShader);
    zombie1.draw(*Resources::Shaders::defaultShader);
}

void Scene1::update(double deltaTime) {
    if (Input::isKeyDown(GLFW_KEY_W)) {
        player.setDirection(graphics::Direction::RIGHT);
        player.move(100 * deltaTime, 0);
        playerCBox.move(100 * deltaTime, 0);
    }
    if (Input::isKeyDown(GLFW_KEY_S)) {
        player.setDirection(graphics::Direction::LEFT);
        player.move(100 * deltaTime, 0);
        playerCBox.move(-100 * deltaTime, 0);
    }
    
    if (Input::isKeyDown(GLFW_KEY_ESCAPE)) {
        Scene::setActive(reinterpret_cast<Scene*>(Scenes::scene0));
    }
    
    if (playerCBox.collided(zombie1CBox) && zombie1CBox.collided(playerCBox)) {
        std::cout << "Player has touched the zombie." << std::endl;
    }
}