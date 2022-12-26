#!/bin/bash

cmake -G "Unix Makefiles" -S . -B build -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ 