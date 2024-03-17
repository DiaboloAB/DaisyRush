cmake_minimum_required(VERSION 3.10)
project(DaisyRush)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Include raylib
set(RAYLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib")
add_subdirectory(${RAYLIB_DIR})

# Include json
set(JSON_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/json")
add_subdirectory(${JSON_DIR})

if(UNIX)
    # Include curlpp
    set(CURLPP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/curlpp")

    # Disable warnings for this subdir
    if(MSVC)
        add_compile_options(/W0)
    else()
        add_compile_options(-w)
    endif()

    add_subdirectory(${CURLPP_DIR})

    # Reset warning level for the rest of the project
    if(MSVC)
        add_compile_options(/W4)
    else()
        add_compile_options(-Wall -Wextra)
    endif()
else()
    # Include entt
    set(ENTT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/entt")
    include_directories(${ENTT_DIR})
endif()

# Include directories
if(UNIX)
    include_directories(${RAYLIB_DIR}/src ${ENTT_DIR} ${CURLPP_DIR}/include ${JSON_DIR}/include)
else()
    include_directories(${RAYLIB_DIR}/src ${ENTT_DIR} ${JSON_DIR}/include)
endif()

# Source files
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Link libraries
if(UNIX)
    target_link_libraries(${PROJECT_NAME} raylib curlpp)
else()
    target_link_libraries(${PROJECT_NAME} raylib)
endif()

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
