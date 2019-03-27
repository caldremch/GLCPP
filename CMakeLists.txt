cmake_minimum_required(VERSION 3.12)
project(GLCPP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")
set(IS_MACOS 0)

set(SOURCE_FILES main.cpp glad/glad.c shader/Shader.cpp shader/Shader.h shape/Triangle.cpp shape/Triangle.h utils/stb_image.h shape/TextureRect.cpp shape/TextureRect.h utils/stb_image_compile.cpp shape/Cube.cpp shape/Cube.h utils/Camera.cpp utils/Camera.h)

add_executable(GLCPP ${SOURCE_FILES})

if (${IS_MACOS} MATCHES 1)

    #Mac 环境
    message("oh mac os !")

    set(GLFW_H /Users/caldremch/work/Code/OpenGL/core/include)

    find_package(OpenGL REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIR})
    find_package(GLUT REQUIRED)
    include_directories(${GLUT_INCLUDE_DIR})

    #添加目标链接
    set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)

    target_link_libraries(GLCPP ${OPENGL_LIBRARY} ${GLEW_LINK} ${GLFW_LINK})


else ()

    #windows 环境
    message("oh windows !")
    set(GLFW_H D:\\MainProject\\OpenGL\\windowscore\\include)
    set(GLAD_H D:\\MainProject\\OpenGL\\glad\\include)
    find_package(OpenGL REQUIRED)

    target_link_libraries(
            GLCPP
            ${OPENGL_LIBRARY}
            #D:\\xxx\\ 会报错
            D:/MainProject/OpenGL/windowscore/libs/libglfw3.a
    )

endif ()

include_directories(${GLFW_H} ${GLAD_H} ${GLM_H})

