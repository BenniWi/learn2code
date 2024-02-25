#!/bin/bash

cmake -G "Unix Makefiles" -S . -B build -D CMAKE_BUILD_TYPE=Debug

cmake --build build