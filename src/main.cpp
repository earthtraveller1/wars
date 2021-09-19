#include <pch.hpp>

#include <Window.hpp>

using wars::Window;

int main()
{
    Window window;
    
    window.show();
    
    while (window.isOpen()) 
    {
        window.update();
    }
    
    return 0;
}