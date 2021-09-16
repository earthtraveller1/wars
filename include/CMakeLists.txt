target_sources(
    "wars" PRIVATE
    
    "engine.hpp"
    "pch.hpp"
)

target_precompile_headers("wars" PRIVATE "pch.hpp")

add_subdirectory("engine")