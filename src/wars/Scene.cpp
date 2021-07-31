#include <graphics/Sprite.hpp>
#include <vector>

#include "Scene.hpp"

using graphics::Sprite;

Scene::Scene(std::vector<Sprite>& p_sprites): sprites(p_sprites) {
    
}

Scene::Scene(std::vector<Sprite>&& p_sprites): sprites(p_sprites) {
    
}

void Scene::render() {
    for (std::vector<Sprite>::iterator i = sprites.begin(); i != sprites.end(); i++) {
        i->draw();
    }
}

void Scene::setActive(Scene& newActive) {
    active = &newActive;
}

void Scene::renderActive() {
    active->render();
}