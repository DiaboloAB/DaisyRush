
if [ "$1" = "build" ]; then
    printf "\033[0;32m[INFO] \033[0mRemoving CMake files\n"
    rm CMakeCache.txt
    rm -rf CMakeFiles
    rm cmake_install.cmake
    rm Makefile
    rm DaisyRush
    printf "\033[0;32m[INFO] \033[0mCMake files removed\n"
    printf "\033[0;32m[INFO] \033[0mBuilding DaisyRush\n"
    cmake .
    make
    printf "\033[0;32m[INFO] \033[0mDaisyRush built\n"
elif [ "$1" = "clean" ]; then
    printf "\033[0;32m[INFO] \033[0mCleaning CMake files\n"
    rm CMakeCache.txt
    rm -rf CMakeFiles
    rm cmake_install.cmake
    rm Makefile
    rm DaisyRush
    printf "\033[0;32m[INFO] \033[0mCMake files cleaned\n"
else
    printf "\033[0;31m[ERROR] \033[0mInvalid argument\n"
    printf "\033[0;31m[ERROR] \033[0mUsage: ./buildMe.sh [build|clean]\n"
fi
