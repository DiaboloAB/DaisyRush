cmake_minimum_required(VERSION 3.10)
project(DaisyRush)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

set(RAYLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib")
set(ENTT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/entt")

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

set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/build")
file(MAKE_DIRECTORY ${BUILD_DIR})

include_directories(${RAYLIB_DIR}/src ${ENTT_DIR})

file(GLOB SOURCES "src/*.cpp" "src/player/*.cpp" "src/player/camera/*.cpp" "src/player/controller/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})

target_link_libraries(${PROJECT_NAME} raylib)
