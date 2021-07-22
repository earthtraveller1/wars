#include <iostream>
#include <glad/glad.h>
#include "Window.hpp"
#include <graphics/basic-utils.hpp>
#include <graphics/Sprite.hpp>
#include <graphics/Material.hpp>
#include <graphics/Shader.hpp>

using graphics::Sprite;
using graphics::Material;
using graphics::Shader;

int main() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window window(0.6, "", false);
    
    Sprite sprite(
        {
            {
                { 0.5, 0.5 },
                { 1.0, 1.0 }
            },
            {
                { 0.5, -0.5 },
                { 1.0, 0.0 }
            },
            {
                { -0.5, -0.5 },
                { 0.0, 0.0 }
            },
            {
                { -0.5, 0.5 },
                { 0.0, 1.0 }
            }
        },
        
        {
            0, 1, 2, 0, 3, 2
        },
        
        Material(Shader("shaders/default.glsl"))
    );
    
    window.show();
    while (window.isOpen()) {
        bgu::clear();
        
        sprite.render();
        
        window.update();
    }
    
    return 0;
}