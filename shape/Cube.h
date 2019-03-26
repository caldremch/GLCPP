//
// Created by Caldremch on 2019/3/26.
//

#ifndef GLCPP_CUBE_H
#define GLCPP_CUBE_H

#include "../shader/Shader.h"

class Cube : public Shader {
public:
    Cube(const GLchar *vertexPath, const GLchar *fragmentPath);
    GLuint texture;
    GLuint texture2;
    void onDestroy();
    void onRelease();
    void use();

};


#endif //GLCPP_CUBE_H
