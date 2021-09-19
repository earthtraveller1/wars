#include <pch.hpp>

#include <glad/glad.h>
#include <Game.hpp>

using wars::Window;

int main()
{
    try
    {
        wars::Game game;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "[FATAL ERROR]: " << e.what() << '\n';
        return -1;
    }
    
    return 0;
}