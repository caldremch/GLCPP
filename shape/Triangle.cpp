//
// Created by Caldremch on 2019/3/22.
//

#include "Triangle.h"

Triangle::Triangle(const GLchar *vertexPath, const GLchar *fragmentPath) : Shader(vertexPath, fragmentPath) {

    float  vertices[] =
            {
                    // positions         // colors
                    0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
                    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
                    0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
            };


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    //对应代码:
    //layout (location = 0) in vec3 aPos;
    //layout (location = 1) in vec3 aColor;
    //顶点 position attribute
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 6* sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //颜色attribute
    glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE, 6* sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Triangle::use() {
    Shader::use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

void Triangle::onRelease() {

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

}


