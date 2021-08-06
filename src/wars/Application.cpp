#include <glad/glad.h>
#include "Window.hpp"
#include <iostream>
#include <graphics/Mesh.hpp>
#include <graphics/TextureAtlas.hpp>
#include <graphics/Shader.hpp>
#include <graphics/ProjectionMatrix.hpp>
#include <graphics/gldb.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Resources.hpp"
#include "Input.hpp"
#include "Time.hpp"
#include "Scenes/Scene0.hpp"
#include "Scenes/Scene1.hpp"
#include "Scenes.hpp"

#include "Application.hpp"

using wars::Application;

using graphics::Mesh;
using graphics::Shader;
using graphics::TextureAtlas;
using graphics::Sprite;

const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 540;

const float ORTHO_PROJ_LEFT = -480.0f;
const float ORTHO_PROJ_RIGHT = 480.0f;
const float ORTHO_PROJ_BOTTOM = -270.0f;
const float ORTHO_PROJ_TOP = 270.0f;

void Application::initWindow() {
    window = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, "@#Wars", false);
    Input::setWindow(*window);
    
    graphics::projectionMatrix = glm::ortho(ORTHO_PROJ_LEFT, ORTHO_PROJ_RIGHT, ORTHO_PROJ_BOTTOM, ORTHO_PROJ_TOP, -1.0f, 1.0f);
}




void Application::initResources() {
    Resources::prepareMeshes();
    Resources::prepareShaders();
    Resources::prepareTextureAtlases();
}




void Application::initScenes() {
    Scenes::scene0 = new Scene0();
    Scenes::scene1 = new Scene1();
    
    Scene::setActive(Scenes::scene0);
}




void Application::initBackgroundColor() {
    // Set the background color
    glCall(glClearColor, 0.0f, 1.0f, 0.0f, 1.0f);
}




Application::Application() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    initWindow();
    initResources();
    initScenes();
    initBackgroundColor();
}




void Application::mainLoop() {
    window->show();
    while (window->isOpen()) {
        double startTime = glfwGetTime();
        
        glCall(glClear, GL_COLOR_BUFFER_BIT);
        
        Resources::Shaders::defaultShader->use();
        Resources::Shaders::defaultShader->setUniform("projection", graphics::projectionMatrix);
        Resources::Shaders::defaultShader->setUniform("textureAtlas", 0);
        
        glCall(glActiveTexture, GL_TEXTURE0);
        
        Scene::renderActive();
        Scene::updateActive(Time.deltaTime);
        
        window->update();
        
        double endTime = glfwGetTime();
        Time.deltaTime = endTime - startTime;
    }
}




Application::~Application() {
    delete Resources::Meshes::player;
    delete Resources::TextureAtlases::atlas1;
    delete Resources::Shaders::defaultShader;
    delete window;
}