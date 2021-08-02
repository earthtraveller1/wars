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

#include "Application.hpp"

using wars::Application;

using graphics::Mesh;
using graphics::Shader;
using graphics::TextureAtlas;
using graphics::Sprite;

const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 540;

void Application::handleInput() {
    if (Input::isKeyDown(GLFW_KEY_W)) {
        player->move(100 * Time.deltaTime, 0);
    }
    if (Input::isKeyDown(GLFW_KEY_S)) {
        player->move(-100 * Time.deltaTime, 0);
    }
}

Application::Application() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    window = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, "@#Wars", false);
    
    Input::setWindow(*window);
    
    float f_windowWidth = static_cast<float>(WINDOW_WIDTH);
    float f_windowHeight = static_cast<float>(WINDOW_HEIGHT);
    graphics::projectionMatrix = glm::ortho(
        -f_windowWidth / 2, f_windowWidth / 2, -f_windowHeight / 2, f_windowHeight / 2, -1.0f, 1.0f
    );
    
    Resources::prepareMeshes();
    Resources::prepareShaders();
    Resources::prepareTextureAtlases();
    
    player = new Sprite(*Resources::Meshes::player);
    
    // Set the background color
    glCall(glClearColor, 0.0f, 1.0f, 0.0f, 1.0f);
}

void Application::mainLoop() {
    window->show();
    while (window->isOpen()) {
        double startTime = glfwGetTime();
        handleInput();
        
        glCall(glClear, GL_COLOR_BUFFER_BIT);
        
        Resources::Shaders::defaultShader->use();
        Resources::Shaders::defaultShader->setUniform("projection", graphics::projectionMatrix);
        Resources::Shaders::defaultShader->setUniform("textureAtlas", 0);
        
        glCall(glActiveTexture, GL_TEXTURE0);
        Resources::TextureAtlases::atlas1->bind();
        
        player->draw(*Resources::Shaders::defaultShader);
        
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