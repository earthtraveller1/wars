target_sources(
    "wars" PRIVATE
    
    "Game.cpp"
    "GameOptions.cpp"
    "Input.cpp"
    "main.cpp"
    "Scene.cpp"
    "Window.cpp"
)

add_subdirectory("scenes")
add_subdirectory("graphics")