//
// Created by Administrator on 2019/3/26.
//

#ifndef GLCPP_CAMERA_H
#define GLCPP_CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement{

    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

//default camera vlaues
const float YAM = -90.0f;
const float PITCH = -0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;



class Camera {

public:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    //Euler Angles
    float Yaw;
    float Pitch;

    //Camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;


};


#endif //GLCPP_CAMERA_H
