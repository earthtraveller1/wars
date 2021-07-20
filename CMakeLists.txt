cmake_minimum_required(VERSION 3.16)

project("Wars")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

option(BUILD_SHARED_LIBS "Whether or not to build shared libraries." OFF)
option(USE_STATIC_LIBS "Wether or not to prefer static libraries over shared ones." OFF)

if (USE_STATIC_LIBS AND NOT MSVC)
    add_link_options("-static")
endif()

find_package("GLFW")

include_directories("include" "${GLFW_INCLUDE_DIR}")

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall")
endif()

add_executable("wars")
add_library("glad")

add_subdirectory("src")
add_subdirectory("include")

target_link_libraries("wars" "glad" "${GLFW_LIBRARY}")