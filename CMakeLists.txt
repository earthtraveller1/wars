cmake_minimum_required(VERSION 3.16)

project("Wars")

include_directories("include")

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall")
endif()

add_executable("wars")
add_library("glad")

add_subdirectory("src")
add_subdirectory("include")

target_link_libraries("wars" "glad")