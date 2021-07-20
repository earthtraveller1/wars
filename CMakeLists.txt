cmake_minimum_required(VERSION 3.16)

project("Wars")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Whether or not to build shared libraries." OFF)
option(USE_STATIC_LIBS "Wether or not to prefer static libraries over shared ones." OFF)
option(ENABLE_OPENGL_DEBUGGING "When true, makes the resulting program check each OpenGL call for errors." OFF)

configure_file("config.in" "config.h")

if (USE_STATIC_LIBS AND NOT MSVC)
    add_link_options("-static")
endif()

find_package("GLFW")
find_package("OpenGL" REQUIRED)

include_directories("include" "${CMAKE_BINARY_DIR}" "${GLFW_INCLUDE_DIR}")

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall")
endif()

add_library("glad")
add_library("graphics")
add_executable("wars")

add_subdirectory("src")
add_subdirectory("include")

if (WIN32)
    target_link_libraries("graphics" "glad" "${GLFW_LIBRARY}" "opengl32")
else()
    target_link_libraries("graphics" "glad" "${GLFW_LIBRARY}" "OpenGL" "dl")
endif()

target_link_libraries("wars" "graphics")