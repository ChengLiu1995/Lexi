# cmake needs this line
cmake_minimum_required(VERSION 2.8)
find_package(OpenGL)
find_package(GLUT REQUIRED) 
find_package(glfw3 REQUIRED) 
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories($(GLEW_INCLUDE_DIRS))
    link_libraries(${GLEW_LIBRARIES})
endif()
message(${CMAKE_CURRENT_SOURCE_DIR}/include/)
add_library(window SHARED
        src/window.cpp
)
target_link_libraries(window glfw ${GLUT_glut_LIBRARY} ${GLUT_glew_LIBRARY} ${GLFW_LIBRARIES})