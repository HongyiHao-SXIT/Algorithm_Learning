# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(Student_Management)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找项目中的所有源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 查找项目中的所有头文件
file(GLOB_RECURSE HEADERS "include/*.h")

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# 指定头文件目录
target_include_directories(${PROJECT_NAME} PRIVATE include)