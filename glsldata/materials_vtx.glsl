#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 FragPos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));

    //法线矩阵 模型矩阵左上角的逆矩阵的转置矩阵
    //计算世界坐标中的 法线矩阵
    //vec3消除了位移的影响
    //作用: 它使用了一些线性代数的操作来移除对法向量错误缩放的影响
    Normal = mat3(transpose(inverse(model))) *aNormal;
    gl_Position = projection * view * vec4(FragPos, 1.0);
}
