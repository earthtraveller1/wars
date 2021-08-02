#include <graphics/Sprite.hpp>
#include <vector>

#include "Scene.hpp"

using graphics::Sprite;

Scene* Scene::active = nullptr;

Scene::Scene() {
    
}

void Scene::setActive(Scene& newActive) {
    active = &newActive;
}

void Scene::renderActive() {
    active->render();
}

void Scene::updateActive() {
    active->update();
}