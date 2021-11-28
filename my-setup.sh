cmake -S deps/glfw -B deps/glfw/build -D GLFW_BUILD_EXAMPLES=false -D GLFW_BUILD_TESTS=false -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ -G Ninja
cmake --build deps/glfw/build

cmake -S . -B build -D GLFW_BUILD_TESTS=false -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ -G Ninja
cmake --build build