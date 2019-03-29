//
// Created by Caldremch on 2019/3/28.
//

#ifndef GLCPP_FILEUTILS_H
#define GLCPP_FILEUTILS_H

#include <boost/filesystem.hpp>
#include <string>

namespace FileSystem {

    const std::string getPath(const char *glslFileName) {

//#ifdef MYMAC
//            const char *glslDir = "glsldata/";
//#else
        //           const char *glslDir = "glsldata\\";
//#endif


//            const char *glslDir = "glsldata";
        std::string glslStr = "glsldata";




        //size_t length = sizeof(glslDir);
        //size_t length1 = sizeof(glslFileName);

        //size_t total = length+length1+1;

        //std::cout << "length = " << length << std::endl;

//        char p[80] = "\0";

//        strcat(p, glslDir);
//        strcat(p, glslFileName);

        //std::cout << "p = " << p << std::endl;

        boost::filesystem::path execPath = boost::filesystem::current_path();

        std::string glslDataRelativePath = glslStr + boost::filesystem::path::preferred_separator + glslFileName;

        std::string rootPath = execPath.parent_path().string();

        std::string absPath = boost::filesystem::complete(glslDataRelativePath, execPath.parent_path()).string();

        return absPath;
    }

}
//
//int main() {
//
//    std::string p1 = FileSystem::getPath("camera_fragment1.glsl");
//    std::string p2 = FileSystem::getPath("camera_fragment2.glsl");
//
//
//    std::string str1 = "well";
//    std::string str2 = "donw";
//    char sep = boost::filesystem::path::preferred_separator;
//
//    std::string str3 = str1+str2+sep;
//
//    std::cout << "path1 address:" << p1 << std::endl;
//    std::cout << "path2 address:" << p2 << std::endl;
//
//    std::cout << "path1 :" << &p1 << std::endl;
//    std::cout << "path2 :" << &p2 << std::endl;
//    std::cout << "str3 :" << str3<< std::endl;
//
//    return 0;
//}


#endif //GLCPP_FILEUTILS_H
