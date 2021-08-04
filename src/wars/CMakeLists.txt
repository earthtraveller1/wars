target_sources(
    "wars" PRIVATE
    
    "Application.cpp"
    "Input.cpp"
    "wars.cpp"
    "Window.cpp"
    "Scene.cpp"
    
    "Application.hpp"
    "Input.hpp"
    "Resources.hpp"
    "Scene.hpp"
    "Time.hpp"
    "Window.hpp"
)

add_subdirectory("Resources")
add_subdirectory("Scenes")
add_subdirectory("sprite-types")