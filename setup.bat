@echo off
cmake -S deps/glfw -B deps/glfw/build
msbuild deps/glfw/build/GLFW.sln

cmake -S . -B build
cmake --build build --target Release