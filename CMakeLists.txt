cmake_minimum_required(VERSION 3.17)
project(OpenGLMaxSat)
file(GLOB GL_SOURCES_DIR "ProjetOpenGL/sources/*")

include_directories(${CMAKE_SOURCE_DIR}/ProjetOpenGL)
link_directories(${CMAKE_SOURCE_DIR}/EvalMaxSAT_HSTT 
                ${CMAKE_SOURCE_DIR}/ProjetOpenGL/libraries/link)

add_executable(${PROJECT_NAME} 
    main.cpp 
    EvalMaxSAT_HSTT/lib/pugixml-1.12/src/pugixml.cpp 
    EvalMaxSAT_HSTT/libipamirEvalMaxSAT2022.a
    ${GL_SOURCES_DIR})

target_link_libraries(${PROJECT_NAME} GL dl glfw IrrKlang ipamirEvalMaxSAT2022 z pthread)