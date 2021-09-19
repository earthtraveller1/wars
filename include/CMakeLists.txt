target_sources(
    "wars" PRIVATE
    
    "Window.hpp"
    "pch.hpp"
)

target_precompile_headers("wars" PRIVATE "pch.hpp")