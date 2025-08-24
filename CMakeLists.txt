cmake_minimum_required(VERSION 3.10.0)
project(BFDIA5B VERSION 0.1.0 LANGUAGES C CXX)

add_executable(BFDIA5B IDFB.cpp Window.cpp Texture.cpp)
find_package(SDL2 REQUIRED CONFIG)
find_package(SDL2_image REQUIRED)
target_link_libraries(BFDIA5B SDL2::SDL2 SDL2::SDL2main SDL2_image)
