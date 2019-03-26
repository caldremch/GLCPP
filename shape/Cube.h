//
// Created by Caldremch on 2019/3/26.
//

#ifndef GLCPP_CUBE_H
#define GLCPP_CUBE_H

#include "../shader/Shader.h"
#include "GLFW/glfw3.h"
class Cube : public Shader {
public:
    Cube();
    Cube(const GLchar *vertexPath, const GLchar *fragmentPath);
    GLuint texture;
    GLuint texture2;
    void onDestroy();
    void onRelease();
    void use();
    glm::vec3 cubePositions[10]  = {
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(2.0f, 5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3(2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f, 3.0f, -7.5f),
            glm::vec3(1.3f, -2.0f, -2.5f),
            glm::vec3(1.5f, 2.0f, -2.5f),
            glm::vec3(1.5f, 0.2f, -1.5f),
            glm::vec3(-1.3f, 1.0f, -1.5f)
    };

    void handleInput(GLFWwindow *window);
};


#endif //GLCPP_CUBE_H
