cmake_minimum_required(VERSION 3.31.6)
project(BFDIA5BA VERSION 0.1.0 LANGUAGES C CXX)

add_executable(BFDIA5BA
    src/IDFB.cpp
)

target_sources(BFDIA5BA
    PRIVATE
    src/Window.cpp
)

# Find SDL2 and SDL2main
find_package(SDL2 REQUIRED)
# Find SDL2_image
find_package(SDL2_image REQUIRED)

# Use imported targets, no need for include_directories
target_link_libraries(BFDIA5BA PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)