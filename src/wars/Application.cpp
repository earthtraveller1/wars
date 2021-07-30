#include <glad/glad.h>
#include "Window.hpp"
#include <iostream>
#include <graphics/Mesh.hpp>
#include <graphics/TextureAtlas.hpp>
#include <graphics/Material.hpp>
#include <graphics/Shader.hpp>
#include <graphics/ProjectionMatrix.hpp>
#include <graphics/gldb.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Resources.hpp"

#include "Application.hpp"

using wars::Application;

using graphics::Mesh;
using graphics::Material;
using graphics::Shader;
using graphics::TextureAtlas;
using graphics::Sprite;

const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 540;

Application::Application() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    window = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, "@#Wars", false);
    
    float f_windowWidth = static_cast<float>(WINDOW_WIDTH);
    float f_windowHeight = static_cast<float>(WINDOW_HEIGHT);
    graphics::projectionMatrix = glm::ortho(-f_windowWidth, f_windowWidth, -f_windowHeight, f_windowHeight, -1.0f, 1.0f);
    
    Resources::prepareMeshes();
    Resources::prepareShaders();
    Resources::prepareTextureAtlases();
    Resources::prepareMaterials();
    
    testSprite = new Sprite(*Resources::Meshes::test, *Resources::Materials::test);
    
    // Set the background color
    glCall(glClearColor, 0.0f, 1.0f, 0.0f, 1.0f);
}

void Application::mainLoop() {
    while (window->isOpen()) {
        glCall(glClear, GL_COLOR_BUFFER_BIT);
        
        testSprite->draw();
        
        window->update();
    }
}

Application::~Application() {
    delete Resources::Meshes::test;
    delete Resources::Materials::test;
    delete Resources::TextureAtlases::test;
    delete Resources::Shaders::defaultShader;
    delete testSprite;
    delete window;
}