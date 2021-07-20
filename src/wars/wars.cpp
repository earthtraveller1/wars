#include <iostream>
#include <glad/glad.h>
#include "Window.hpp"
#include <graphics/basic-utils.hpp>

int main() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window window(1.0, "", true);
    
    window.show();
    while (window.isOpen()) {
        bgu::clear();
        
        window.update();
    }
    
    return 0;
}