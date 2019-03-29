#version 330 core

out vec4 FragColor;

//材质
struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;//反光度
};

struct Light{

    vec3 position;
    vec3 ambient;//环境反射的强度
    vec3 diffuse;//
    vec3 specular;//镜面光照的强度
};


in vec3 Normal;
in vec3 FragPos;


//uniform vec3 objectColor;//物体颜色
//uniform vec3 lightColor;//灯光颜色
//uniform vec3 lightPos;//灯光位置
uniform Material material;
uniform Light light;


uniform vec3 viewPos;//观察位置

void main() {


    //环境
    float ambientStrenth = 0.1;
    //    vec3 ambient = ambientStrenth*lightColor;
    vec3 ambient = light.ambient*material.ambient;

    //漫反射
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);//相机向量-片段向量
    //我们对norm和lightDir向量进行点乘，计算光源对当前片段实际的漫反射影响。结果值再乘以光的颜色，得到漫反射分量。两个向量之间的角度越大，漫反射分量就会越小
    float diff = max(dot(norm, lightDir), 0.0);
    //漫反射向量
    vec3 diffuse = light.diffuse*(diff*material.diffuse);

    //specular 镜面反射
    //float specularStrength = 0.5;//设置镜面光照的强度
    vec3 viewDir = normalize(viewPos - FragPos);// 计算出观察向量

    //reflectDir ----> lightDir 向量在法线向量 norm 的反射向量
    vec3 reflectDir = reflect(-lightDir, norm);

    //dot算视线方向与反射方向的点乘 然后取它的32次幂 32次幂代表反光度, 2~256 32为中等
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);//等到镜面分量
    //镜面反射向量 vec3
    vec3 specular = light.specular* (spec * material.specular);

    //环境光分量和漫反射分量，我们把它们相加，然后把结果乘以物体的颜色，来获得片段最后的输出颜色
    vec3 result = ambient + diffuse + specular;

    FragColor = vec4(result, 1.0);
}
