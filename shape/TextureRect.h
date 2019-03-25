//
// Created by Caldremch on 2019/3/23.
//

#ifndef OPENGLC_TEXTURERECT_H
#define OPENGLC_TEXTURERECT_H


#include "../shader/Shader.h"

class TextureRect : Shader{
public:
    TextureRect(const GLchar *vertexPath, const GLchar *fragmentPath);
    void use();
    void onRelease();
    GLuint texture;
    GLuint texture2;

};


#endif //OPENGLC_TEXTURERECT_H
