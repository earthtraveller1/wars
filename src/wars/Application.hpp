#ifndef B5AA26B1_009A_4288_B03C_2A1468B4E642
#define B5AA26B1_009A_4288_B03C_2A1468B4E642

#include "Window.hpp"
#include <graphics/TextureAtlas.hpp>
#include <graphics/Shader.hpp>
#include <graphics/Material.hpp>
#include <graphics/Mesh.hpp>
#include <graphics/Sprite.hpp>

namespace wars {
    // The class that represents the entire application
    class Application {
    private:
        // The Window
        Window* window;
        
        graphics::Sprite* testSprite;
    public:
        // Constructor
        Application();
        
        // Main Loop
        void mainLoop();
        
        // Destructor
        ~Application();
    };
}

#endif /* B5AA26B1_009A_4288_B03C_2A1468B4E642 */
