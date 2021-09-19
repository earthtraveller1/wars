target_sources(
    "wars" PRIVATE
    
    "Game.hpp"
    "pch.hpp"
    "Window.hpp"
)

target_precompile_headers("wars" PRIVATE "pch.hpp")