cmake_minimum_required(VERSION 3.10)
project(DaisyRush)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Include raylib
set(RAYLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib")
add_subdirectory(${RAYLIB_DIR})

# Include ENTT if necessary
# set(ENTT_DIR "<path_to_ENTT>")

# Include directories
include_directories(${RAYLIB_DIR}/src ${ENTT_DIR})

# Source files
file(GLOB SOURCES "src/*.cpp" "src/player/*.cpp" "src/player/camera/*.cpp" "src/player/controller/*.cpp")

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Link libraries
target_link_libraries(${PROJECT_NAME} raylib)

# Copy assets folder to the bin directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/assets"
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

# Use CPack to package the project
install(TARGETS ${PROJECT_NAME}
    DESTINATION .
)

# Put the assets folder in the package
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assets"
    DESTINATION .
)

set(CPACK_PACKAGE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")

# Set the working directory for the installed executable
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_INSTALL_PREFIX}"
)

include(CPack)
