#include <pch.hpp>
#include <Game.hpp>
#include <scenes/TestScene.hpp>

using wars::Game;
using wars::scenes::TestScene;

Game::Game(): m_input(m_window)
{
    std::cout << "[INFO]: Using OpenGL " << glGetString(GL_VERSION) << "\n";
    int maximumTextureSize = 0;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maximumTextureSize);
    std::cout << "[INFO]: Maximum Texture size is " << maximumTextureSize << "\n";
    
    Scene::setActiveScene<TestScene>();
}





void Game::mainLoop()
{
    // Show the window only when the main loop has began.
    m_window.show();
    
    while (m_window.isOpen())
    {
        Scene::updateActiveScene();
        Scene::renderActiveScene();
        
        m_window.update();
    }
}




Game::~Game()
{
    Scene::removeActiveScene();
}