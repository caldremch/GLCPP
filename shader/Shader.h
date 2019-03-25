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



class Shader {

public:
    //程序 id
    GLuint ID;

    //构造器
    Shader(const GLchar*vertexPath, const GLchar *fragmentPath);

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
};


#endif //OPENGLC_SHADER_H
