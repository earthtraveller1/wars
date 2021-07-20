#include <iostream>
#include "Window.hpp"

int main() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window window(1.0, "", true);
    
    window.show();
    while (window.isOpen()) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        window.update();
    }
    
    return 0;
}