cmake_minimum_required(VERSION 3.10)
project(achievement_management VERSION 1.0 LANGUAGE CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(achievement_management
    src/main.cpp)

target_include_directories(achievement_management PUBLIC include)