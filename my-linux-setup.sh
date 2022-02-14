#!/bin/bash
cd Dependencies/scp-game-framework
./my-setup-linux.sh
cd ../..
cmake -S . -B Build -G Ninja -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ -D CMAKE_BUILD_TYPE=Debug
cmake --build Build