# cmake needs this line
cmake_minimum_required(VERSION 2.8)
find_package(OpenGL)
find_package(GLUT REQUIRED) 
find_package(glfw3 REQUIRED) 
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_library(command SHARED
        src/insert_command.cpp
)
