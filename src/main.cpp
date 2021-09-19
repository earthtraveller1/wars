#include <pch.hpp>

#include <glad/glad.h>
#include <Window.hpp>

using wars::Window;

int main()
{
    Window window;
    
    window.show();
    
    glClearColor(0.0f, 1.0f, 0.0, 1.0f);
    
    while (window.isOpen()) 
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        window.update();
    }
    
    return 0;
}