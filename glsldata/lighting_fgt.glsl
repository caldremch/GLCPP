#version 330 core

out vec4 FragColor;


in vec3 Normal;
in vec3 FragPos;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;

void main() {


    /*

           简单的环境光
           float ambientStrenth = 0.1;

           vec3 ambient  =  ambientStrenth*lightColor;

           vec3 result = ambient * objectColor;*/



    //反射光
    float ambientStrenth = 0.1;
    vec3 ambient  =  ambientStrenth*lightColor;

    //diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos); //相机向量-片段向量

    //我们对norm和lightDir向量进行点乘，计算光源对当前片段实际的漫发射影响。结果值再乘以光的颜色，得到漫反射分量。两个向量之间的角度越大，漫反射分量就会越小
    float diff = max(dot(norm, lightDir), 0.0);

    //漫反射向量
    vec3 diffuse = diff*lightColor;

    //环境光分量和漫反射分量，我们把它们相加，然后把结果乘以物体的颜色，来获得片段最后的输出颜色
    vec3 result = (ambient + diffuse) * objectColor;

    FragColor = vec4(result, 1.0);
}
