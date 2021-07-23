#include <iostream>
#include <glad/glad.h>
#include "Window.hpp"
#include <graphics/basic-utils.hpp>
#include <graphics/Mesh.hpp>
#include <graphics/Material.hpp>
#include <graphics/Shader.hpp>
#include <glm/gtc/matrix_transform.hpp>

using graphics::Mesh;
using graphics::Material;
using graphics::Shader;

const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 540;

int main() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "@#Wars", false);
    
    Mesh mesh(
        {
            {
                { 10.0, 10.0 },
                { 1.0, 1.0 }
            },
            {
                { 10.0, -10.0 },
                { 10.0, 0.0 }
            },
            {
                { -10.0, -10.0 },
                { 0.0, 0.0 }
            },
            {
                { -10.0, 10.0 },
                { 0.0, 1.0 }
            }
        },
        {
            0, 1, 2, 0, 3, 2
        }
    );
    
    Material material(Shader("shaders/default.glsl"));
    
    glm::mat4 model(1.0f);
    
    float f_windowWidth = static_cast<float>(WINDOW_WIDTH);
    float f_windowHeight = static_cast<float>(WINDOW_HEIGHT);
    glm::mat4 projection = glm::ortho(-f_windowWidth, f_windowWidth, -f_windowHeight, f_windowHeight, -1.0f, 1.0f);
    
    material.use();
    material.setUniform("projection", projection);
    
    window.show();
    while (window.isOpen()) {
        bgu::clear();
        
        material.use();
        material.setUniform("model", model);
        
        mesh.render();
        
        window.update();
    }
    
    return 0;
}