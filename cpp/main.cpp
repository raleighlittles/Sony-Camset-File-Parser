/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <filesystem>

#include "camset.h"

int main(int argc, char* argv[]) {

    if (argc != 2) {

        std::cerr << "Incorrect number of arguments, expected 2" << std::endl;
        return 1;
    }


    const std::string camsetFile(argv[1]);

    if (!std::filesystem::exists(camsetFile)) {
        std::cerr << "Error: File " << argv[1] << " does not exist" << std::endl;
        return 2;
    }

    Camset camsetObj = Camset(camsetFile);

    std::cout << "Camera model is = " << camsetObj.getCameraMakeModel() << std::endl;

    std::cout << "File name is: " << camsetObj.getFileName() << std::endl;

    std::cout << "File created date: " << camsetObj.getFileDate() << std::endl;

    return 0;
}