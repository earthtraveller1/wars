#include <scp/Window.hpp>
#include <scp/Scene.hpp>
#include <scp/utils/time-utils.hpp>
#include <scp/graphics/opengl.hpp>
#include <scp/graphics/Renderer2D.hpp>
#include "MenuScene.hpp"
#include <scp/utils/file-utils.hpp>
#include <scp/graphics/opengl.hpp>

using scp::Window;
using scp::Scene;
using scp::graphics::Renderer2D;
namespace fileutils = scp::utils::file_utils;
namespace OpenGL = scp::graphics::opengl;

int main()
{
    Window& window = Window::getInstance(
        Window::SCREEN_SIZE_TIMES_66_PERCENT, // The width of the window.
        Window::SCREEN_SIZE_TIMES_66_PERCENT, // The height of the window.
        "Wars", // The text in the titlebar
        false, // fullscreen
        scp::graphics::API::OpenGL, // graphics API to utilise
        true // graphics debugging
    );
    
    Renderer2D renderer(scp::graphics::API::OpenGL, fileutils::loadAsString("../share/wars/assets/OpenGLRenderer.glsl"));
    renderer.addTexture("../share/wars/assets/TextureAtlas.png");
    OpenGL::setClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    
    Scene::setActive<MenuScene, Renderer2D&>(renderer);
    
    window.show();
    
    double lastTime = 0;
    
    while (window.isOpen())
    {
        double currentTime = scp::time_utils::getGLFWTime();
        double deltaTime = currentTime - lastTime;
        lastTime = currentTime;
        
        scp::graphics::opengl::clearColor();
        
        Scene::updateActive(deltaTime);
        Scene::renderActive();
        
        window.update();
    }
}
