#!/bin/bash

pullSubmodules() {
    printf "\033[0;32m[INFO] \033[0mPulling submodules\n"
    git submodule update --init --recursive
    printf "\033[0;32m[INFO] \033[0mSubmodules pulled\n"
}

buildDaisyRush() {
    printf "\033[0;32m[INFO] \033[0mBuilding DaisyRush\n"
    cmake -S . -B build
    cmake --build build -j
    printf "\033[0;32m[INFO] \033[0mDaisyRush built\n"
}

cleanCMakeFiles() {
    printf "\033[0;32m[INFO] \033[0mRemoving CMake files\n"
    cmake --build build --target clean
    rm -rf build
    printf "\033[0;32m[INFO] \033[0mCMake files removed\n"
}

if [ "$1" = "build" ]; then
    pullSubmodules
    buildDaisyRush
elif
    [ "$1" = "clean" ]; then
    cleanCMakeFiles
else
    printf "\033[0;31m[ERROR] \033[0mInvalid argument\n"
fi
