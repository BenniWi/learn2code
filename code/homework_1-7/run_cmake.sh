#!/bin/bash

cmake -G "Unix Makefiles" -S . -B build -D CMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Release
cd build
make