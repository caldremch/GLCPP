cmake_minimum_required(VERSION 3.12)
project(GLCPP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")
set(IS_MACOS 0)
message("ok?")
message("is macos? --> ${IS_MACOS}")
#添加头文件
#set(GLEW_H /usr/local/Cellar/glew/2.1.0/include/GL)
set(GLFW_H D:\\MainProject\\OpenGL\\windowscore\\include)
set(GLAD_H D:\\ m MainProject\\OpenGL\\glad\\include)

if (${IS_MACOS} MATCHES 1)
    set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include/GLFW)
    set(GLAD_H /usr/local/include/glad/include)
    set(GLM_H /usr/local/include/glm)
    #添加目标链接
    set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.dylib)
    set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
    find_package(OpenGL REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIR})
    find_package(GLUT REQUIRED)
    include_directories(${GLUT_INCLUDE_DIR})
endif ()

include_directories(${GLFW_H} ${GLAD_H})

set(SOURCE_FILES main.cpp)

add_executable(OpenGLCPP ${SOURCE_FILES})