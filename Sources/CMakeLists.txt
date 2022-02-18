add_executable(
    "wars"
    
    "Main.cpp"
    "MenuScene.cpp"
    
    "MenuScene.hpp"
)

target_link_libraries(
    "wars"
    
    "scp-game-framework-core"
    "scp-game-framework-utils"
    "scp-game-framework-graphics"
    "scp-game-framework-ui"
)