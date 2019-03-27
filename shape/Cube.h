//
// Created by Caldremch on 2019/3/26.
//

#ifndef GLCPP_CUBE_H
#define GLCPP_CUBE_H

#include "../shader/Shader.h"
#include "GLFW/glfw3.h"
#include "../utils/Camera.h"

static Camera camera_ss(glm::vec3(0.0f, 0.0f, 3.0f));

class Cube : public Shader {

public:


    //照相机数据
    float deltaTimeCube = 0.0f;
    float lastFrameCube = 0.0f;
    float lastX = SCR_WIDTH / 2.0f;
    float lastY = SCR_HEIGHT / 2.0f;
    bool firstMouse = true;
// timing
    float deltaTimeCal = 0.0f;    // time between current frame and last frame
    float lastFrameCal = 0.0f;


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


    void processInput_(GLFWwindow *window) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera_ss.ProcessKeyboard(FORWARD, deltaTimeCal);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera_ss.ProcessKeyboard(BACKWARD, deltaTimeCal);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera_ss.ProcessKeyboard(LEFT, deltaTimeCal);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera_ss.ProcessKeyboard(RIGHT, deltaTimeCal);
    }


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
    void framebuffer_size_callback_(GLFWwindow *window, int width, int height) {
        // make sure the viewport matches the new window dimensions; note that width and
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
    }


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
    void mouse_callback_(GLFWwindow *window, double xpos, double ypos) {
        if (firstMouse) {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

        lastX = xpos;
        lastY = ypos;

        camera_ss.ProcessMouseMovement(xoffset, yoffset);
    }

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
    void scroll_callback_(GLFWwindow *window, double xoffset, double yoffset) {
        camera_ss.ProcessMouseScroll(yoffset);
    }
};


#endif //GLCPP_CUBE_H
