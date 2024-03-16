
printf "\033[0;32m[INFO] \033[0mRemoving CMake files\n"
rm CMakeCache.txt
rm -rf CMakeFiles
rm cmake_install.cmake
rm Makefile
rm build/DaisyRush
rm DaisyRush
printf "\033[0;32m[INFO] \033[0mCMake files removed\n"
printf "\033[0;32m[INFO] \033[0mBuilding DaisyRush\n"
if [ "$1" = "build" ]; then
    cmake .
    make
    printf "\033[0;32m[INFO] \033[0mDaisyRush built\n"
fi
