cmake_minimum_required(VERSION 3.10.0)
project(BFDIA5BA VERSION 0.1.0 LANGUAGES C CXX)

add_executable(BFDIA5BA
                src/IDFB.cpp
)

target_sources(BFDIA5BA PRIVATE
                src/TextureAtlas.cpp
                src/Texture.cpp
                src/Window.cpp
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2 REQUIRED CONFIG)
find_package(SDL2_image REQUIRED)

target_link_libraries(BFDIA5BA SDL2::SDL2 SDL2::SDL2main SDL2_image)

