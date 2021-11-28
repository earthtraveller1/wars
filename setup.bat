@echo off
cmake -S deps/glfw -B deps/glfw/build -D GLFW_BUILD_EXAMPLES=false -D GLFW_BUILD_TESTS=false
cmake --build deps/glfw/build --target Release

cmake -S . -B build
cmake --build build --target Release