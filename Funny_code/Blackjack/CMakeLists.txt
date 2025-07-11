cmake_minimum_required(VERSION 3.10)
project(Blackjack VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Blackjack 
    src/main.cpp
    src/Game.cpp
)

target_include_directories(Blackjack PUBLIC include) 