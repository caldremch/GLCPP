# GLCPP  OpenGL C++ 学习


这里是根据 OpenGl learn 网站学习的, 大部分代码跟 https://learnopengl-cn.github.io/ 是一样, 当然, 网站上的代码只是
用于帮助你如何理解 OpenGL 的知识, 实际使用来需要根据情况来定.


项目中的环境配置如下

#Mac 环境配置
1.clion + cmake + glfw3 + glad + OpenGL + mac + (boost)

这些环境中, 重点就是glfw3安装, 在 mac 很简单
brew install glfw 

网上说有需要添加额外的比如UITookit或者 VideoKit 等, 那可能是你用了 Xcode 来开发, 
所有需要的, 但是在 clion 这里是不需要的, 因为我已经测试过了

详细请看项目中的 CMakeLists.txt的配置



boost 只是用来了它的 filesystem 组件, 用来对路径进行处理

#Windows 环境配置 
1.clion + cmake + glfw3 + glad + Windows + (boost)

windows 的配置就是血泪史


glfw 要编译 这个编译如果不知道, 刚开始会走很多弯路
使用 cmake 来编译 glfw (我的版本是3.2.1) , 如果 cmake 没有, 则去下载
 
 
这里说几个关键点:

1.在编译的时候, 会让你选择 编译器的选择, 如果是 visual studio 使用, 则选择 visual studio, 编译出来的只有 visual 
里面的项目可以使用, 如果你也把库放到clion 来使用, 那么是会报错的.


2.如果你喜欢使用 clion 来开发,  那么在 windows 这里可能会麻烦点, 没事, 只要步骤都走对了, 那么也不是什么问题

1.首先, 你的知道你的 clion 使用的minGW 版本, 如果clion 里面使用的是你clion 自带的, 那么你需要
自己去下载 minGW 来安装, 然后配置到环境变量, 同时配置到你的 clion 里面, 用于替换原有的 mingw
在 cmd 命令控制台 输入 mingw32-make命令的时候 是有效的

2.然后在使用 cmake 编译的时候选择 mingw 这里生成的库才可以使用在 clion 上面







