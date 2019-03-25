//
// Created by Caldremch on 2019/3/22.
//

#ifndef OPENGLC_TRIANGLE_H
#define OPENGLC_TRIANGLE_H

#include "../shader/Shader.h"

class Triangle : Shader{
public:
    Triangle(const GLchar *vertexPath, const GLchar *fragmentPath);
    void use();
    void onRelease();

};


#endif //OPENGLC_TRIANGLE_H
