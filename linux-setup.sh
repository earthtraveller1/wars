#!/bin/bash
cd Dependencies/scp-game-framework
./setup-linux.sh
cd ../..
cmake -S . -B Build -G Ninja
cmake --build Build