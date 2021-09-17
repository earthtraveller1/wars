cmake_minimum_required(VERSION 3.16)

project("Wars")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_BUILD_RPATH "$ORIGIN:$ORIGIN/../lib")

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-pedantic")
endif()

find_package("GLFW")

add_executable("wars")

target_include_directories("wars" PRIVATE "include" "${GLFW_INCLUDE_DIR}")

target_link_libraries("wars" "${GLFW_LIBRARY}")

add_subdirectory("src")
add_subdirectory("include")