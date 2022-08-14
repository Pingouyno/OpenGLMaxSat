cmake_minimum_required(VERSION 3.17)
project(OpenGLMaxSat)
file(GLOB GL_SOURCES_DIR "ProjetOpenGL/sources/*")

include_directories(${CMAKE_SOURCE_DIR}/ProjetOpenGL
                    ${CMAKE_SOURCE_DIR}/ProjetOpenGL/libraries/include)
link_directories(${CMAKE_SOURCE_DIR}/ProjetOpenGL/libraries/link)

add_executable(${PROJECT_NAME} 
    ProjetOpenGL/main.cpp 
    ${GL_SOURCES_DIR})


target_link_libraries(${PROJECT_NAME} GL dl glfw IrrKlang)