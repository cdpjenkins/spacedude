cmake_minimum_required(VERSION 3.18)
project(spacedude)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set (CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(spacedude
        src/Asteroid.cpp
        src/Bullet.cpp
        src/Player.cpp
        src/Entity.cpp
        src/Game.cpp
        src/SDLContext.cpp
        src/Shield.cpp
        src/Sprite.cpp
        src/main.cpp)

target_link_libraries(spacedude ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

file(
    COPY assets
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)
