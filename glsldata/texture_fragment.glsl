#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TextCoord;

//texture sampler
uniform sampler2D texture1;
uniform sampler2D texture2;



void main()
{
//    FragColor = texture(texture1, TextCoord)*vec4(ourColor, 1.0);
    //texture1 80%  texture2 20%
    FragColor = mix(texture(texture1, TextCoord), texture(texture2, TextCoord), 0.2);

}