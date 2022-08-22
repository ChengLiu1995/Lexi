# cmake needs this line
cmake_minimum_required(VERSION 2.8)
find_package(OpenGL)
find_package(GLUT REQUIRED) 
find_package(glfw3 REQUIRED) 
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_SOURCE_DIR}/common/include/
)
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories($(GLEW_INCLUDE_DIRS))
    link_libraries(${GLEW_LIBRARIES})
endif()

message(${CMAKE_CURRENT_SOURCE_DIR}/../common/include/)

add_library(window SHARED
        src/window.cpp
        src/button.cpp
        src/gl_render_helper.cpp
        src/hmi_event.cpp
)
target_link_libraries(window glfw command ${GLUT_glut_LIBRARY} ${OPENGL_LIBRARIES} ${GLUT_glew_LIBRARY} ${OPENGL_glu_LIBRARIES} ${GLFW_LIBRARIES})