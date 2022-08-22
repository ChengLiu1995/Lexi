# cmake needs this line
cmake_minimum_required(VERSION 2.8)
project(Lexi)

add_subdirectory(command)
add_subdirectory(window)

add_executable(main main.cpp)
target_link_libraries(main command window)