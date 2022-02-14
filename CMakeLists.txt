cmake_minimum_required(VERSION "3.13")

project("Wars")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Application/bin")
set(CMAKE_CXX_STANDARD "17")

if (NOT MSVC)
    add_compile_options("-Wall" "-Wextra")
else()
    add_compile_options("/Wall")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options("-Weverything" "-fdiagnostics-absolute-paths")
endif()

add_subdirectory("Sources")