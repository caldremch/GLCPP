cmake_minimum_required(VERSION 3.12)
project(GLCPP)


#-DBoost_DEBUG=ON
#-DBoost_USE_STATIC_LIBS=ON
#-DBoost_USE_MULTITHREADED=ON

set (Boost_USE_STATIC_LIBS ON) # enable dynamic linking
set (Boost_USE_MULTITHREAD ON)  # enable multithreading

#添加编译条件
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")



if (${WIN32})
    message("WIN32 match system: ${WIN32}")

    #cmake 在 find_path 和 find_library 时，会搜索一些默认的路径。当我们将一些lib安装在非默认搜索路径时，cmake就没法搜索到了。这是我们需要添加路径
    SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "D:\\MainProject\\OpenGL\\boost_1_69_0")
    SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "D:\\MainProject\\OpenGL\\boost_1_69_0\\stage\\lib")

    #添加库文件搜索路径, 注意: link_directories 一定要放在 add_executable前面
    link_directories(D:\\MainProject\\OpenGL\\boost_1_69_0\\stage\\lib)

endif ()

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    message("match system: ${CMAKE_SYSTEM_NAME}")
endif ()



set(SOURCE_FILES specularMain.cpp main.cpp glad/glad.c shader/Shader.cpp shader/Shader.h shape/Triangle.cpp shape/Triangle.h utils/stb_image.h shape/TextureRect.cpp shape/TextureRect.h utils/stb_image_compile.cpp shape/Cube.cpp shape/Cube.h utils/Camera.h camermaMain.cpp lightMain.cpp utils/FileUtils.h)

add_executable(GLCPP ${SOURCE_FILES})


#####################################Mac 环境###################################
if (${APPLE})
    message("oh mac os !")

    #add boost, component filesystem
    find_package(Boost REQUIRED COMPONENTS filesystem)

    if (NOT Boost_FOUND)
        message("Not found Boost")
    endif ()

    set(GLFW_H /Users/caldremch/work/Code/OpenGL/core/include)

    find_package(OpenGL REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIR})

    # find_package(GLUT REQUIRED)
   # include_directories(${GLUT_INCLUDE_DIR})

    #添加目标链接
    set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)

    target_link_libraries(GLCPP
            ${OPENGL_LIBRARY}
            #${GLEW_LINK}
            ${GLFW_LINK}
            ${Boost_LIBRARIES}
            )

#####################################windows 环境####################################
else ()

    message("oh windows !")

    find_package(Boost)

    if(NOT Boost_FOUND)
        message("not found boost package")
    else()
        message("found boost package")
        include_directories(${Boost_INCLUDE_DIR})
        LINK_DIRECTORIES(${CMAKE_LIBRARY_PATH})
        ## ADD_DEFINITIONS("-DHAS_BOOST")
        message("includes: ${Boost_INCLUDE_DIRS}")
        message("libs: ${Boost_LIBRARIES}") #这个变量在windows下找不到，为空
    endif()



    #添加头文件搜索路径
    include_directories(D:\\MainProject\\OpenGL\\boost_1_69_0)

        #添加 glfw glm 等头文件集合
    set(GLFW_H D:\\MainProject\\OpenGL\\windowscore\\include)
    set(GLAD_H D:\\MainProject\\OpenGL\\glad\\include)

        #寻找系统的 OpenGL 库
    find_package(OpenGL REQUIRED)

    target_link_libraries(
            GLCPP
            ${OPENGL_LIBRARY}
            #D:\\xxx\\ 会报错
            D:/MainProject/OpenGL/windowscore/libs/libglfw3.a
            libboost_filesystem-mgw82-mt-d-x32-1_69.a
            libboost_system-mgw82-mt-d-x32-1_69.a
    )

endif ()

include_directories(${GLFW_H} ${GLAD_H} ${GLM_H} ${Boost_INCLUDE_DIRS})

#show boost
message("Boost_INCLUDE_DIRS -----> ${Boost_INCLUDE_DIRS}")
message("Boost_LIBRARIES -----> ${Boost_LIBRARIES}")

