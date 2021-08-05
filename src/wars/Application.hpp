#ifndef B5AA26B1_009A_4288_B03C_2A1468B4E642
#define B5AA26B1_009A_4288_B03C_2A1468B4E642

#include "Window.hpp"
#include <graphics/TextureAtlas.hpp>
#include <graphics/Shader.hpp>
#include <graphics/Mesh.hpp>
#include <graphics/Sprite.hpp>
#include "Scenes/Scene1.hpp"
#include "Scenes/Scene0.hpp"

namespace wars {
    // The class that represents the entire application
    class Application {
    private:
        Window* window;
        
        Scene0* scene0;
        Scene1* scene1;
    public:
        Application();
        
        void mainLoop();
        
        ~Application();
    };
}

#endif /* B5AA26B1_009A_4288_B03C_2A1468B4E642 */
