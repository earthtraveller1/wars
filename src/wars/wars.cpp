#include "Application.hpp"
#include <stdexcept>
#include <iostream>

static void start() {
    wars::Application app;
    app.mainLoop();
}

int main() {
    try {
        start();
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}