cmake_minimum_required(VERSION 3.10)
project(DaisyRush)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Set the path to the Raylib directory within your project
set(RAYLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib")

# Add Raylib library
if(WIN32)
    # Assuming raylib is provided as a .lib file on Windows
    add_library(raylib STATIC IMPORTED)
    set_target_properties(raylib PROPERTIES IMPORTED_LOCATION "${RAYLIB_DIR}/raylib.lib")
elseif(UNIX)
    # Assuming raylib is provided as either a .so or .a file on Unix-like systems
    # add_library(raylib STATIC IMPORTED)
    # set_target_properties(raylib PROPERTIES IMPORTED_LOCATION "${RAYLIB_DIR}/libraylib.a")
    # For dynamic linking, uncomment the following lines:
    add_library(raylib SHARED IMPORTED)
    set_target_properties(raylib PROPERTIES IMPORTED_LOCATION "${RAYLIB_DIR}/src/libraylib.so")
endif()

# Include directories
include_directories(${RAYLIB_DIR}/src)

# Add your game's source files
add_executable(${PROJECT_NAME} src/main.cpp)

# Link Raylib library
target_link_libraries(${PROJECT_NAME} raylib)
