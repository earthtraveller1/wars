

#include <graphics/Shaders.hpp>

using wars::graphics::Shaders;

Shaders& Shaders::getInstance()
{
    static Shaders shaders;
    return shaders;
}




std::string Shaders::loadAsString(std::string_view path)
{
    return path.data();
}