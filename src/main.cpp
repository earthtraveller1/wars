#include <pch.hpp>
#include <engine.hpp>

int main() {
    wars::engine engine;
    
    while (true) {
        engine.render();
        engine.update();
    }
    
    return 0;
}