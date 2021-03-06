//
// Created by Caldremch on 2019/3/22.
//

#ifndef OPENGLC_SHADER_H
#define OPENGLC_SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class Shader {

public:
    //程序 id
    GLuint ID;

    //构造器
    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);

    Shader();

    GLchar *vertexPath;
    GLchar *fragmentPath;

    void setVertexPath(GLchar *vertexPath);

    void setFragmentPath(GLchar *fragmentPath);

    //使用, 激活程序
    virtual void use();

    //uniform工具函数
    void setBool(const std::string &name, bool value) const;

    void setInt(const std::string &name, int value) const;

    void setFloat(const std::string &name, float value) const;

    //检查错误
    void checkCompileError(GLuint shader, std::string type);


    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    virtual void onRelease();

    void setMat2(const std::string &name, const glm::mat2 &mat) const;

    void setMat3(const std::string &name, const glm::mat3 &mat) const;

    void setMat4(const std::string &name, const glm::mat4 &mat) const;

    void setVec3(const std::string &name, const glm::vec3 &value) const {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    void setVec3(const std::string &name, float x, float y, float z) const {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }
};


#endif //OPENGLC_SHADER_H
