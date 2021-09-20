#include <Scene.hpp>

wars::Scene* wars::Scene::active = nullptr;

void wars::Scene::removeActiveScene()
{
    delete active;
    active = nullptr;
}