cmake_minimum_required(VERSION 3.10)
project(DaisyRush)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

set(RAYLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib")
add_subdirectory(${RAYLIB_DIR})

include_directories(${RAYLIB_DIR}/src ${ENTT_DIR})

file(GLOB SOURCES "src/*.cpp" "src/player/*.cpp" "src/player/camera/*.cpp" "src/player/controller/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

target_link_libraries(${PROJECT_NAME} raylib)
