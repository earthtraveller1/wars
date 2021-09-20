target_sources(
    "wars" PRIVATE
    
    "Game.hpp"
    "GameOptions.hpp"
    "Input.hpp"
    "pch.hpp"
    "Scene.hpp"
    "Window.hpp"
)

target_precompile_headers("wars" PRIVATE "pch.hpp")

add_subdirectory("scenes")
add_subdirectory("graphics")