cmake_minimum_required(VERSION 3.15)
project(Battle_City LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
  add_compile_options(/W4 /permissive-)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(tank_battle
    src/main.cpp
    src/Game.cpp
    src/Tank.cpp
    src/Projectile.cpp
    src/Utils.cpp
    src/Map.cpp
)

target_include_directories(Battle_City PRIVATE ${CMAKE_SOURCE_DIR}/include)
