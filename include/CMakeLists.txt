target_sources(
    "wars" PRIVATE
    
    "Game.hpp"
    "GameOptions.hpp"
    "Input.hpp"
    "Math.hpp"
    "pch.hpp"
    "Scene.hpp"
    "Window.hpp"
)

target_precompile_headers("wars" PRIVATE "pch.hpp")

configure_file("cmake_config.ini" "cmake_config.h")

add_subdirectory("scenes")
add_subdirectory("graphics")
add_subdirectory("math")