#include "../Resources.hpp"
#include <graphics/TextureAtlas.hpp>
#include <glad/glad.h>
#include <graphics/gldb.hpp>
#include "../Scenes.hpp"

#include "Scene0.hpp"

Scene0::Scene0(): background(*Resources::Meshes::scene0Background),
                  playButton(*Resources::Meshes::playButton, {78, -78, 37, -37}),
                  otherButton(*Resources::Meshes::otherButton, {102, -102, 37, -37}) {
    playButton.move(-334.0f, 115.0f);
    otherButton.move(-310.0f, 15.0f);
}

void Scene0::render() {
    Resources::TextureAtlases::atlas0->bind();
    background.draw(*Resources::Shaders::defaultShader);
    playButton.draw(*Resources::Shaders::defaultShader);
    otherButton.draw(*Resources::Shaders::defaultShader);
}

void Scene0::update(double deltaTime) {
    if (playButton.isClicked()) {
        Scene::setActive(reinterpret_cast<Scene*>(Scenes::scene1));
    }
}