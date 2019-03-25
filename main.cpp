//
// Created by Caldremch on 2019/3/22.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shape/Triangle.h"
#include "shape/TextureRect.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow *window);


int main() {

//    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
//
//    glm::mat4 trans;
//
//    trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
//
//    vec = trans*vec;
//
//    std::cout << vec.x << vec.y << vec.z << std::endl;
//
//    if (1){ return 0; }

    GLFWwindow *window = NULL;
    if (!glfwInit()) {
        std::cout << "init failed" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //如果是 mac 系统要加上这句, 不然会创建出窗口失败
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "GLCompile", NULL, NULL);

    if (!window)
    {
        std::cout << "init window failed" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


//    Triangle triangle("../glsldata/trangle_vertex.glsl", "../glsldata/trangle_fragment.glsl");

    TextureRect textureRect("../glsldata/texture_vertex.glsl", "../glsldata/texture_fragment.glsl");


    while (!glfwWindowShouldClose(window)){

        // input
        // -----
        processInput(window);
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        textureRect.use();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    textureRect.onRelease();
    glfwTerminate();
    return 0;
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    std::cout << "改变了:"<< width << "," << height << std::endl;
    glViewport(0, 0, width, height);
}
