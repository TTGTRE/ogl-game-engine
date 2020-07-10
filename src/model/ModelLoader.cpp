//
// Created by Tre on 6/29/2020.
//

#include <fstream>
#include <iostream>
#include <vector>
#include "ModelLoader.h"

GLuint ModelLoader::index = 0;

Model *ModelLoader::load(std::string filePath) {
    std::ifstream stream(filePath, std::ios::in);
    if (!stream)
        std::cout << "Error opening file: " << filePath << "\n";
    auto *floatVec = new std::vector<float>();
    float f = 0;
    while (stream >> f)
        floatVec->push_back(f);
    floatVec->shrink_to_fit();
    stream.close();
    return new Model(index++, floatVec->data(), floatVec->size());
}