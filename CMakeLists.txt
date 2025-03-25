cmake_minimum_required(VERSION 3.18)
project(spacedude)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

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

target_link_libraries(spacedude
        PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

file(
    COPY assets
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)
