#include <Game.hpp>

using wars::Game;

Game::Game(): m_input(m_window)
{
    
}





void Game::mainLoop()
{
    // Show the window only when the main loop has began.
    m_window.show();
    
    while (m_window.isOpen())
    {
        m_window.update();
    }
}




Game::~Game()
{
    
}