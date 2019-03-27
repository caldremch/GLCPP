#version 330 core

out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main() {


    float ambientStrenth = 0.1;

    vec3 ambient  =  ambientStrenth*lightColor;

    vec3 result = ambient * objectColor;

    //反射光
    FragColor = vec4(result, 1.0);
}
