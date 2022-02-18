#include <scp/Window.hpp>
#include <scp/Scene.hpp>

#include <scp/utils/time-utils.hpp>

#include <scp/graphics/opengl.hpp>

#include "MenuScene.hpp"

using scp::Window;
using scp::Scene;

int main()
{
    Window& window = Window::getInstance(Window::SCREEN_SIZE_TIMES_66_PERCENT, Window::SCREEN_SIZE_TIMES_66_PERCENT, "Wars", false, scp::graphics::API::OpenGL, true);
    
    Scene::setActive<MenuScene>();
    
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
