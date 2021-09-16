#include <pch.hpp>

#include <engine.hpp>

wars::engine::engine() {
    std::cout << "[INFO]: Starting Engine." << std::endl;
}

void wars::engine::update() {
    std::cout << "[INFO]: Updating Engine." << std::endl;
}

void wars::engine::render() {
    std::cout << "[INFO]: Rendering Engine." << std::endl;
}

wars::engine::~engine() {
    std::cout << "[INFO]: Closing Engine." << std::endl;
}