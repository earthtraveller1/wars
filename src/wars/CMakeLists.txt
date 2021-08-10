target_sources(
    "wars" PRIVATE
    
    "Application.cpp"
    "CollisionBox.cpp"
    "Input.cpp"
    "Scene.cpp"
    "Scenes.cpp"
    "wars.cpp"
    "Window.cpp"
    
    "Application.hpp"
    "CollisionBox.hpp"
    "Input.hpp"
    "Resources.hpp"
    "Scene.hpp"
    "Scenes.hpp"
    "Time.hpp"
    "Window.hpp"
)

add_subdirectory("Resources")
add_subdirectory("Scenes")
add_subdirectory("sprite-types")