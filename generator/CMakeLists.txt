cmake_minimum_required(VERSION 3.17)

#Project Name

PROJECT(generator)
set(PROJECT_NAME generator)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)



add_executable(${PROJECT_NAME} main.cpp models/plano.cpp  models/box.cpp  models/sphere.cpp  models/cone.cpp bezierPatch.cpp bezierPatch.h)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

if  (WIN32)

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

else (WIN32) #Linux and Mac

    set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} Wno-deprecated")

endif(WIN32)






