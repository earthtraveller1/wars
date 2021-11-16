cmake_minimum_required(VERSION 3.16)

project("Wars")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_BUILD_RPATH "$ORIGIN:$ORIGIN/../lib")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

if (WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
endif()

if (UNIX AND NOT APPLE)
    set(CMAKE_EXECUTABLE_SUFFIX ".out")
endif()

if (MSVC)
    add_compile_options("/Wall")
else()
    add_compile_options("-Wall" "-Wextra" "-pedantic")
endif()

find_package("GLFW")

add_executable("wars")
add_library("GLAD" "deps/GLAD/src/glad.c")

target_include_directories(
    "wars" PRIVATE "deps/GLAD/include" "include" "${GLFW_INCLUDE_DIR}" "${CMAKE_BINARY_DIR}/include"
)
target_include_directories("GLAD" PRIVATE "deps/GLAD/include")

target_link_libraries("wars" "GLAD" "${GLFW_LIBRARY}")

if (UNIX AND NOT APPLE)
    target_link_libraries("wars" "dl")
endif()

add_subdirectory("src")
add_subdirectory("include")