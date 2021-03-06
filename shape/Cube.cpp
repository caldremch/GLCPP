//
// Created by Caldremch on 2019/3/26.
//

#include "Cube.h"
#include "../utils/stb_image.h"
#include <GLFW/glfw3.h>

//camera by mouse
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);


void framebuffer_size_callback(GLFWwindow *window, int width, int height);


void processInput(GLFWwindow *window);


Cube::Cube(const GLchar *vertexPath, const GLchar *fragmentPath) : Shader(vertexPath, fragmentPath) {


    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    float vertices[] = {
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
    };


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //position vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    //color attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //texture1
    //load and create a texture
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    //set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //load image , create texture and generate mipmaps
    GLint width, height, nrChannels;
    std::string path = "../res/container.jpg";
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

    //GL_RGB
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);


    //texture2
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    path = "../res/awesomeface.png";

    //在图片加载之前设置
    stbi_set_flip_vertically_on_load(true);
    data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    //GL_RGBA
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture2" << std::endl;
    }
    stbi_image_free(data);

    glUseProgram(ID);
    //使用glUniform1i设置每个采样器的方式告诉OpenGL每个着色器采样器属于哪个纹理单元
    glUniform1i(glGetUniformLocation(ID, "texture1"), 0);
    setInt("texture2", 1);
    glm::mat4 projection = glm::mat4(1.0f);//投影矩阵
    projection = glm::perspective(glm::radians(45.0f), (float) 800 / (float) 600.0f, 0.1f, 100.0f);
    setMat4("projection", projection);

}

void Cube::onRelease() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Cube::use() {


    float currentFrame = glfwGetTime();
    deltaTimeCube = currentFrame - lastFrameCube;
    lastFrameCube = currentFrame;

    //纹理单元GL_TEXTURE0默认总是被激活
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    Shader::use();

//    glm::mat4 model = glm::mat4(1.0f);//模型矩阵
//    glm::mat4 view = glm::mat4(1.0f);//观察矩阵
//    glm::mat4 projection = glm::mat4(1.0f);//投影矩阵

//    model = glm::rotate(model, (float) glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));




//    unsigned int modelLoc = glGetUniformLocation(ID, "model");
//    unsigned int viewLoc = glGetUniformLocation(ID, "view");
    // pass them to the shaders (3 different ways)
//    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
    // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.

    //camera
//    float radius = 10.0f;
//    float camX = sin(glfwGetTime())*radius;
//    float camZ = cos(glfwGetTime())*radius;
//    glm::mat4 view = glm::mat4(1.0f);//观察矩阵
//    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//    //摄像机位置 , 目标, 上向量
//    view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//    setMat4("view", view);

    glm::mat4 projection = glm::perspective(glm::radians(camera_ss.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    setMat4("projection", projection);

    // camera/view transformation
    glm::mat4 view = camera_ss.GetViewMatrix();
    setMat4("view", view);

    //glm::mat4 view = glm::mat4(1);
    //view = glm::lookAt(cameraPos, (cameraPos.operator+=(cameraFront)), cameraUp);
    glBindVertexArray(VAO);

    for (int i = 0; i < 10; ++i) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }


}

void Cube::handleInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        std::cout << "退出" << std::endl;
        glfwSetWindowShouldClose(window, true);
    }

    float cameraSpeed = 2.5*deltaTimeCube;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        std::cout << "W 键" << std::endl;
        cameraPos += cameraFront.operator*=(cameraSpeed) ;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        std::cout << "S 键" << std::endl;
        cameraPos -= cameraFront.operator*=(cameraSpeed);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        std::cout << "A 键" << std::endl;
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        std::cout << "D 键" << std::endl;
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }

}

void Cube::onDestroy() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

Cube::Cube() {

}
